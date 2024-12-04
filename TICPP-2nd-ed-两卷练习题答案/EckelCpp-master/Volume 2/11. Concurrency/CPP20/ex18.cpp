// �޸�CarBuilder_CPP20.cpp��Ϊ�����˸����ʶ��������Ӹ��಻ͬ��������˵�ʵ�����Ƿ����л����˶��õ������ã�

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
    bool engine, driveTrain, wheels, paint;
public:
    Car(int idn) : id(idn), engine(false), driveTrain(false), wheels(false), paint(false) {}
    Car() : id(-1), engine(false), driveTrain(false), wheels(false), paint(false) {}
    int getId() { return id; }
    void addEngine() { engine = true; }
    bool engineInstalled() { return engine; }
    void addDriveTrain() { driveTrain = true; }
    bool driveTrainInstalled() { return driveTrain; }
    void addWheels() { wheels = true; }
    bool wheelsInstalled() { return wheels; }
    void addPaint() { paint = true; }
    bool paintApplied() { return paint; }
    friend ostream& operator<<(ostream& os, const Car& c) {
        return os << "���� " << c.id << " ["
                  << " ������: " << c.engine
                  << " ����ϵͳ: " << c.driveTrain
                  << " ����: " << c.wheels
                  << " ����: " << c.paint
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

    bool engineBotHired, wheelBotHired, driveTrainBotHired, paintBotHired;

public:
    Cradle() : occupied(false), engineBotHired(true), wheelBotHired(true), driveTrainBotHired(true), paintBotHired(true) {}

    void insertCar(Car chassis) {
        c = chassis;
        occupied = true;
    }

    Car getCar() {
        if (!occupied) {
            cerr << " getCar()û�д�Cradle����ȡ��Car" << endl;
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

    void offerPaintBotServices() {
        unique_lock<mutex> lock(workMutex);
        while (paintBotHired) workCondition.wait(lock);
        paintBotHired = true;
    }

    void startWork() {
        lock_guard<mutex> lock(workMutex);
        engineBotHired = false;
        wheelBotHired = false;
        driveTrainBotHired = false;
        paintBotHired = false;
        workCondition.notify_all();  // ͨ���㲥�����߻����˿��Կ�ʼ������
    }

    void taskFinished() {
        lock_guard<mutex> lock(readyMutex);
        readyCond.notify_one();
    }

    void waitUntilWorkFinished() {
        unique_lock<mutex> lock(readyMutex);
        readyCond.wait(lock, [this] { return c.engineInstalled() && c.driveTrainInstalled() && c.wheelsInstalled() && c.paintApplied(); });
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
    int id;
public:
    EngineRobot(Cradle& cr, int ident) : cradle(cr), id(ident) {}

    void operator()() {
        while (true) {
            cradle.offerEngineBotServices();
            cout << "������������ " << id << " ��װ������" << endl;
            cradle->addEngine();
            cradle.taskFinished();
        }
    }
};

class DriveTrainRobot {
    Cradle& cradle;
    int id;
public:
    DriveTrainRobot(Cradle& cr, int ident) : cradle(cr), id(ident) {}

    void operator()() {
        while (true) {
            cradle.offerDriveTrainBotServices();
            cout << "����ϵͳ������ " << id << " ��װ����ϵͳ" << endl;
            cradle->addDriveTrain();
            cradle.taskFinished();
        }
    }
};

class WheelRobot {
    Cradle& cradle;
    int id;
public:
    WheelRobot(Cradle& cr, int ident) : cradle(cr), id(ident) {}

    void operator()() {
        while (true) {
            cradle.offerWheelBotServices();
            cout << "���ֻ����� " << id << " ��װ����" << endl;
            cradle->addWheels();
            cradle.taskFinished();
        }
    }
};

class PaintRobot {
    Cradle& cradle;
    int id;
public:
    PaintRobot(Cradle& cr, int ident) : cradle(cr), id(ident) {}

    void operator()() {
        while (true) {
            cradle.offerPaintBotServices();
            cout << "��������� " << id << " ����������" << endl;
            cradle->addPaint();
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
    cout << "�밴<Enter>���˳�" << endl;

    TQueue<Car> chassisQueue;
    TQueue<Car> finishingQueue;
    Cradle cradle;

    vector<thread> assemblyLine;
    for (int i = 1; i <= 3; ++i) {
        assemblyLine.emplace_back(EngineRobot(cradle, i));
        assemblyLine.emplace_back(DriveTrainRobot(cradle, i));
        assemblyLine.emplace_back(WheelRobot(cradle, i));
        assemblyLine.emplace_back(PaintRobot(cradle, i));
    }
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
