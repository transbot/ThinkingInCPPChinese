//: C11:CarBuilder.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ�㲥�Ĺ�������
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
    // �հ�Car����
    Car() : id(-1), engine(false), driveTrain(false), wheels(false) {}
    // ��ͬ�������ٶ�bool������ԭ�ӵģ�
    int getId() { return id; }
    void addEngine() { engine = true; }
    bool engineInstalled() { return engine; }
    void addDriveTrain() { driveTrain = true; }
    bool driveTrainInstalled() { return driveTrain; }
    void addWheels() { wheels = true; }
    bool wheelsInstalled() { return wheels; }
    friend ostream& operator<<(ostream& os, const Car& c) {
        return os << "���� " << c.id << " ["
                  << " ������: " << c.engine
                  << " ����ϵͳ: " << c.driveTrain
                  << " ����: " << c.wheels
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
                // ����һ���µ��̣�
                Car c(counter++);
                cout << c << endl;
                // ����������
                carQueue->put(c);
            }
        } catch(Interrupted_Exception&) {
            // �˳�
        }
        cout << "ChassisBuilder�����������ߣ��ر�" << endl;
    }
};

// �о��࣬���в�����������װ��
class Cradle {
    Car c; // �����˵�ǰ����װ�������
    bool occupied; // �Ƿ�ռ��
    Mutex workLock, readyLock;
    Condition workCondition, readyCondition;

    // ���ֻ������Ƿ񱻡���Ӷ��
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
    Car getCar() { // ֻ����ȡһ������
        if(!occupied) {
            cerr << " getCar()û�д�Cradle ����ȡ��Car" << endl;
            return Car(); // ���ա���������
        }
        occupied = false;
        return c;
    }

    // ����Cradle�е�����
    Car* operator->() { return &c; }

    // ������������Cradle�ṩ����
    void offerEngineBotServices() {
        Guard<Mutex> g(workLock);
        while(engineBotHired) workCondition.wait();
        engineBotHired = true; // ���ܹ���
    }
    void offerWheelBotServices() {
        Guard<Mutex> g(workLock);
        while(wheelBotHired) workCondition.wait();
        wheelBotHired = true; // ���ܹ���
    }
    void offerDriveTrainBotServices() {
        Guard<Mutex> g(workLock);
        while(driveTrainBotHired) workCondition.wait();
        driveTrainBotHired = true; // ���ܹ���
    }

    // ��֪�ȴ��Ļ����˹���׼������
    void startWork() {
        Guard<Mutex> g(workLock);
        engineBotHired = false;
        wheelBotHired = false;
        driveTrainBotHired = false;
        workCondition.broadcast(); // ͨ���㲥�����߻����˿��Կ�ʼ������
    }

    // ÿ�������˱������ǵĹ��������
    void taskFinished() {
        Guard<Mutex> g(readyLock);
        readyCondition.signal();
    }

    // Director�ȴ����й������
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
                // ������ֱ�����̿��ã�
                cradle->insertCar(chassisQueue->get());
                // ֪ͨ����������׼����װ����
                cradle->startWork();
                // �ȴ��������
                cradle->waitUntilWorkFinished();
                // �����������վ�����У��Խ�����һ���Ĺ���
                finishingQueue->put(cradle->getCar());
            }
        } catch(Interrupted_Exception&) {
            // �˳�
        }
        cout << "Director�ر�" << endl;
    }
};

// ����װ�䷢�����Ļ�����
class EngineRobot : public Runnable {
    CradlePtr cradle;
public:
    EngineRobot(CradlePtr cr) : cradle(cr) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                // ������ֱ���������ṩ/���ܣ�
                cradle->offerEngineBotServices();
                cout << "��װ������" << endl;
                (*cradle)->addEngine();
                cradle->taskFinished();
            }
        } catch(Interrupted_Exception&) {
            // �˳�
        }
        cout << "�����������ˣ�EngineBot���ر�" << endl;
    }
};

// ����װ�䴫��ϵͳ�Ļ�����
class DriveTrainRobot : public Runnable {
    CradlePtr cradle;
public:
    DriveTrainRobot(CradlePtr cr) : cradle(cr) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                // ������ֱ���������ṩ/���ܣ�
                cradle->offerDriveTrainBotServices();
                cout << "��װ����ϵͳ" << endl;
                (*cradle)->addDriveTrain();
                cradle->taskFinished();
            }
        } catch(Interrupted_Exception&) {
            // �˳�
        }
        cout << "����ϵͳ�����ˣ�DriveTrainBot���ر�" << endl;
    }
};

// ����װ�䳵�ֵĻ�����
class WheelRobot : public Runnable {
    CradlePtr cradle;
public:
    WheelRobot(CradlePtr cr) : cradle(cr) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                // ����ֱ���������ṩ/���ܣ�
                cradle->offerWheelBotServices();
                cout << "��װ����" << endl;
                (*cradle)->addWheels();
                cradle->taskFinished();
            }
        } catch(Interrupted_Exception&) {
            // �˳�
        }
        cout << "���ֻ����ˣ�WheelBot���ر�" << endl;
    }
};

// ����౨����
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
            // �˳�
        }
        cout << "Reporter�ر�" << endl;
    }
};

int main() {
    cout << "�밴<Enter>���˳�" << endl;
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

        // ��ʼ������������������װ�����
        assemblyLine.execute(new ChassisBuilder(chassisQueue));

        cin.get();
        assemblyLine.interrupt();
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
