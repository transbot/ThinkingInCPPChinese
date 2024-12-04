//: C11:CarBuilder_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示现代C++的广播机制（在条件变量上调用notify_all()）
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "TQueue_CPP20.h"
#include <vector>

using namespace std;

class Car {
    int id;
    bool engine, driveTrain, wheels;
public:
    Car(int idn) : id(idn), engine(false), driveTrain(false), wheels(false) {}
    Car() : id(-1), engine(false), driveTrain(false), wheels(false) {}
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

class ChassisBuilder {
    TQueue<Car>& carQueue;
    int counter;
public:
    ChassisBuilder(TQueue<Car>& cq) : carQueue(cq), counter(0) {}

    void operator()() {
        while (true) {
            this_thread::sleep_for(chrono::seconds(1));
            Car c(counter++);
            cout << c << endl;
            carQueue.put(c);
        }
    }
};

class Cradle {
    Car c;
    bool occupied;
    mutex workMutex, readyMutex;
    condition_variable workCondition, readyCond;

    bool engineBotHired, wheelBotHired, driveTrainBotHired;

public:
    Cradle() : occupied(false), engineBotHired(true), wheelBotHired(true), driveTrainBotHired(true) {}

    void insertCar(Car chassis) {
        c = chassis;
        occupied = true;
    }

    Car getCar() {
        if (!occupied) {
            cerr << " getCar()没有从Cradle中提取到Car" << endl;
            return Car();
        }
        occupied = false;
        return c;
    }

    Car* operator->() { return &c; }

    void offerEngineBotServices() {
        unique_lock<mutex> lock(workMutex);
        while (engineBotHired) workCondition.wait(lock);
        engineBotHired = true;
    }

    void offerWheelBotServices() {
        unique_lock<mutex> lock(workMutex);
        while (wheelBotHired) workCondition.wait(lock);
        wheelBotHired = true;
    }

    void offerDriveTrainBotServices() {
        unique_lock<mutex> lock(workMutex);
        while (driveTrainBotHired) workCondition.wait(lock);
        driveTrainBotHired = true;
    }

    void startWork() {
        lock_guard<mutex> lock(workMutex);
        engineBotHired = false;
        wheelBotHired = false;
        driveTrainBotHired = false;
        workCondition.notify_all();  // 通过广播来告诉机器人可以开始工作了
    }

    void taskFinished() {
        lock_guard<mutex> lock(readyMutex);
        readyCond.notify_one();
    }

    void waitUntilWorkFinished() {
        unique_lock<mutex> lock(readyMutex);
        readyCond.wait(lock, [this] { return c.engineInstalled() && c.driveTrainInstalled() && c.wheelsInstalled(); });
    }
};

class Director {
    TQueue<Car>& chassisQueue;
    TQueue<Car>& finishingQueue;
    Cradle& cradle;
public:
    Director(TQueue<Car>& cq, TQueue<Car>& fq, Cradle& cr) : chassisQueue(cq), finishingQueue(fq), cradle(cr) {}

    void operator()() {
        while (true) {
            cradle.insertCar(chassisQueue.get());
            cradle.startWork();
            cradle.waitUntilWorkFinished();
            finishingQueue.put(cradle.getCar());
        }
    }
};

class EngineRobot {
    Cradle& cradle;
public:
    EngineRobot(Cradle& cr) : cradle(cr) {}

    void operator()() {
        while (true) {
            cradle.offerEngineBotServices();
            cout << "安装发动机" << endl;
            cradle->addEngine();
            cradle.taskFinished();
        }
    }
};

class DriveTrainRobot {
    Cradle& cradle;
public:
    DriveTrainRobot(Cradle& cr) : cradle(cr) {}

    void operator()() {
        while (true) {
            cradle.offerDriveTrainBotServices();
            cout << "安装传动系统" << endl;
            cradle->addDriveTrain();
            cradle.taskFinished();
        }
    }
};

class WheelRobot {
    Cradle& cradle;
public:
    WheelRobot(Cradle& cr) : cradle(cr) {}

    void operator()() {
        while (true) {
            cradle.offerWheelBotServices();
            cout << "安装车轮" << endl;
            cradle->addWheels();
            cradle.taskFinished();
        }
    }
};

class Reporter {
    TQueue<Car>& carQueue;
public:
    Reporter(TQueue<Car>& cq) : carQueue(cq) {}

    void operator()() {
        while (true) {
            cout << carQueue.get() << endl;
        }
    }
};

int main() {
    cout << "请按<Enter>键退出" << endl;

    TQueue<Car> chassisQueue;
    TQueue<Car> finishingQueue;
    Cradle cradle;

    vector<thread> assemblyLine;
    assemblyLine.emplace_back(EngineRobot(cradle));
    assemblyLine.emplace_back(DriveTrainRobot(cradle));
    assemblyLine.emplace_back(WheelRobot(cradle));
    assemblyLine.emplace_back(Director(chassisQueue, finishingQueue, cradle));
    assemblyLine.emplace_back(Reporter(finishingQueue));

    ChassisBuilder chassisBuilder(chassisQueue);
    thread chassisBuilderThread(chassisBuilder);

    cin.get();
    chassisBuilderThread.detach();

    for (auto& t : assemblyLine) {
        t.detach();
    }

    return 0;
}
