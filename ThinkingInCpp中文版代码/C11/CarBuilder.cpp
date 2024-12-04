//: C11:CarBuilder.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示广播的工作机制
//{L} ZThread
#include <iostream>
#include <string>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include "zthread/Condition.h"
#include "zthread/ThreadedExecutor.h"
#include "TQueue.h"
using namespace ZThread;
using namespace std;

class Car {
    int id;
    bool engine, driveTrain, wheels;
public:
    Car(int idn) : id(idn), engine(false), driveTrain(false), wheels(false) {}
    // 空白Car对象：
    Car() : id(-1), engine(false), driveTrain(false), wheels(false) {}
    // 不同步——假定bool运算是原子的：
    int getId() { return id; }
    void addEngine() { engine = true; }
    bool engineInstalled() { return engine; }
    void addDriveTrain() { driveTrain = true; }
    bool driveTrainInstalled() { return driveTrain; }
    void addWheels() { wheels = true; }
    bool wheelsInstalled() { return wheels; }
    friend ostream& operator<<(ostream& os, const Car& c) {
        return os << "汽车 " << c.id << " ["
                  << " 发动机: " << c.engine
                  << " 传动系统: " << c.driveTrain
                  << " 车轮: " << c.wheels
                  << " ]";
    }
};

typedef CountedPtr< TQueue<Car> > CarQueue;

class ChassisBuilder : public Runnable {
    CarQueue carQueue;
    int counter;
public:
    ChassisBuilder(CarQueue& cq) : carQueue(cq), counter(0) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                Thread::sleep(1000);
                // 生产一个新底盘：
                Car c(counter++);
                cout << c << endl;
                // 将其插入队列
                carQueue->put(c);
            }
        } catch(Interrupted_Exception&) {
            // 退出
        }
        cout << "ChassisBuilder（底盘生产者）关闭" << endl;
    }
};

// 夹具类，所有部件均在这里装配
class Cradle {
    Car c; // 容纳了当前正在装配的汽车
    bool occupied; // 是否被占用
    Mutex workLock, readyLock;
    Condition workCondition, readyCondition;

    // 三种机器人是否被“雇佣”
    bool engineBotHired, wheelBotHired, driveTrainBotHired; 
public:
    Cradle() : workCondition(workLock), readyCondition(readyLock) {
        occupied = false;
        engineBotHired = true;
        wheelBotHired = true;
        driveTrainBotHired = true;
    }
    void insertCar(Car chassis) {
        c = chassis;
        occupied = true;
    }
    Car getCar() { // 只能提取一次汽车
        if(!occupied) {
            cerr << " getCar()没有从Cradle 中提取到Car" << endl;
            return Car(); // “空”汽车对象
        }
        occupied = false;
        return c;
    }

    // 访问Cradle中的汽车
    Car* operator->() { return &c; }

    // 允许机器人向此Cradle提供服务
    void offerEngineBotServices() {
        Guard<Mutex> g(workLock);
        while(engineBotHired) workCondition.wait();
        engineBotHired = true; // 接受工作
    }
    void offerWheelBotServices() {
        Guard<Mutex> g(workLock);
        while(wheelBotHired) workCondition.wait();
        wheelBotHired = true; // 接受工作
    }
    void offerDriveTrainBotServices() {
        Guard<Mutex> g(workLock);
        while(driveTrainBotHired) workCondition.wait();
        driveTrainBotHired = true; // 接受工作
    }

    // 告知等待的机器人工作准备就绪
    void startWork() {
        Guard<Mutex> g(workLock);
        engineBotHired = false;
        wheelBotHired = false;
        driveTrainBotHired = false;
        workCondition.broadcast(); // 通过广播来告诉机器人可以开始工作了
    }

    // 每个机器人报告他们的工作已完成
    void taskFinished() {
        Guard<Mutex> g(readyLock);
        readyCondition.signal();
    }

    // Director等待所有工作完成
    void waitUntilWorkFinished() {
        Guard<Mutex> g(readyLock);
        while(!(c.engineInstalled() && c.driveTrainInstalled()
                && c.wheelsInstalled()))
            readyCondition.wait();
    }
};

typedef CountedPtr<Cradle> CradlePtr;

class Director : public Runnable {
    CarQueue chassisQueue, finishingQueue;
    CradlePtr cradle;
public:
    Director(CarQueue& cq, CarQueue& fq, CradlePtr cr) : 
        chassisQueue(cq), finishingQueue(fq), cradle(cr) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                // 阻塞，直到底盘可用：
                cradle->insertCar(chassisQueue->get());
                // 通知机器人汽车准备好装配了
                cradle->startWork();
                // 等待工作完成
                cradle->waitUntilWorkFinished();
                // 将汽车放入出站队列中，以进行下一步的工作
                finishingQueue->put(cradle->getCar());
            }
        } catch(Interrupted_Exception&) {
            // 退出
        }
        cout << "Director关闭" << endl;
    }
};

// 负责装配发动机的机器人
class EngineRobot : public Runnable {
    CradlePtr cradle;
public:
    EngineRobot(CradlePtr cr) : cradle(cr) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                // 阻塞，直到工作被提供/接受：
                cradle->offerEngineBotServices();
                cout << "安装发动机" << endl;
                (*cradle)->addEngine();
                cradle->taskFinished();
            }
        } catch(Interrupted_Exception&) {
            // 退出
        }
        cout << "发动机机器人（EngineBot）关闭" << endl;
    }
};

// 负责装配传动系统的机器人
class DriveTrainRobot : public Runnable {
    CradlePtr cradle;
public:
    DriveTrainRobot(CradlePtr cr) : cradle(cr) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                // 阻塞，直到工作被提供/接受：
                cradle->offerDriveTrainBotServices();
                cout << "安装传动系统" << endl;
                (*cradle)->addDriveTrain();
                cradle->taskFinished();
            }
        } catch(Interrupted_Exception&) {
            // 退出
        }
        cout << "传动系统机器人（DriveTrainBot）关闭" << endl;
    }
};

// 负责装配车轮的机器人
class WheelRobot : public Runnable {
    CradlePtr cradle;
public:
    WheelRobot(CradlePtr cr) : cradle(cr) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                // 阻塞直到工作被提供/接受：
                cradle->offerWheelBotServices();
                cout << "安装车轮" << endl;
                (*cradle)->addWheels();
                cradle->taskFinished();
            }
        } catch(Interrupted_Exception&) {
            // 退出
        }
        cout << "车轮机器人（WheelBot）关闭" << endl;
    }
};

// 这个类报告结果
class Reporter : public Runnable {
    CarQueue carQueue;
public:
    Reporter(CarQueue& cq) : carQueue(cq) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                cout << carQueue->get() << endl;
            }
        } catch(Interrupted_Exception&) {
            // 退出
        }
        cout << "Reporter关闭" << endl;
    }
};

int main() {
    cout << "请按<Enter>键退出" << endl;
    try {
        CarQueue chassisQueue(new TQueue<Car>),
                   finishingQueue(new TQueue<Car>);
        CradlePtr cradle(new Cradle);
        ThreadedExecutor assemblyLine;
        assemblyLine.execute(new EngineRobot(cradle));
        assemblyLine.execute(new DriveTrainRobot(cradle));
        assemblyLine.execute(new WheelRobot(cradle));
        assemblyLine.execute(new Director( 
            chassisQueue, finishingQueue, cradle));
        assemblyLine.execute(new Reporter(finishingQueue));

        // 开始生产底盘来启动整个装配过程
        assemblyLine.execute(new ChassisBuilder(chassisQueue));

        cin.get();
        assemblyLine.interrupt();
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
