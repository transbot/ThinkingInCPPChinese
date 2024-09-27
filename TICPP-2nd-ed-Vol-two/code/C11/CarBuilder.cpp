//: C11:CarBuilder.cpp {RunByHand}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// How broadcast() works.
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
  Car(int idn) : id(idn), engine(false),
  driveTrain(false), wheels(false) {}
  // Empty Car object:
  Car() : id(-1), engine(false),
  driveTrain(false), wheels(false) {}
  // Unsynchronized -- assumes atomic bool operations:
  int getId() { return id; }
  void addEngine() { engine = true; }
  bool engineInstalled() { return engine; }
  void addDriveTrain() { driveTrain = true; }
  bool driveTrainInstalled() { return driveTrain; }
  void addWheels() { wheels = true; }
  bool wheelsInstalled() { return wheels; }
  friend ostream& operator<<(ostream& os, const Car& c) {
    return os << "Car " << c.id << " ["
      << " engine: " << c.engine
      << " driveTrain: " << c.driveTrain
      << " wheels: " << c.wheels << " ]";
  }
};

typedef CountedPtr< TQueue<Car> > CarQueue;

class ChassisBuilder : public Runnable {
  CarQueue carQueue;
  int counter;
public:
  ChassisBuilder(CarQueue& cq) : carQueue(cq),counter(0) {}
  void run() {
    try {
      while(!Thread::interrupted()) {
        Thread::sleep(1000);
        // Make chassis:
        Car c(counter++);
        cout << c << endl;
        // Insert into queue
        carQueue->put(c);
      }
    } catch(Interrupted_Exception&) { /* Exit */ }
    cout << "ChassisBuilder off" << endl;
  }
};

class Cradle {
  Car c; // Holds current car being worked on
  bool occupied;
  Mutex workLock, readyLock;
  Condition workCondition, readyCondition;
  bool engineBotHired, wheelBotHired, driveTrainBotHired;
public:
  Cradle()
  : workCondition(workLock), readyCondition(readyLock) {
    occupied = false;
    engineBotHired = true;
    wheelBotHired = true;
    driveTrainBotHired = true;
  }
  void insertCar(Car chassis) {
    c = chassis;
    occupied = true;
  }
  Car getCar() { // Can only extract car once
    if(!occupied) {
      cerr << "No Car in Cradle for getCar()" << endl;
      return Car(); // "Null" Car object
    }
    occupied = false;
    return c;
  }
  // Access car while in cradle:
  Car* operator->() { return &c; }
  // Allow robots to offer services to this cradle:
  void offerEngineBotServices() {
    Guard<Mutex> g(workLock);
    while(engineBotHired)
      workCondition.wait();
    engineBotHired = true; // Accept the job
  }
  void offerWheelBotServices() {
    Guard<Mutex> g(workLock);
    while(wheelBotHired)
      workCondition.wait();
    wheelBotHired = true; // Accept the job
  }
  void offerDriveTrainBotServices() {
    Guard<Mutex> g(workLock);
    while(driveTrainBotHired)
      workCondition.wait();
    driveTrainBotHired = true; // Accept the job
  }
  // Tell waiting robots that work is ready:
  void startWork() {
    Guard<Mutex> g(workLock);
    engineBotHired = false;
    wheelBotHired = false;
    driveTrainBotHired = false;
    workCondition.broadcast();
  }
  // Each robot reports when their job is done:
  void taskFinished() {
    Guard<Mutex> g(readyLock);
    readyCondition.signal();
  }
  // Director waits until all jobs are done:
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
  Director(CarQueue& cq, CarQueue& fq, CradlePtr cr)
  : chassisQueue(cq), finishingQueue(fq), cradle(cr) {}
  void run() {
    try {
      while(!Thread::interrupted()) {
        // Blocks until chassis is available:
        cradle->insertCar(chassisQueue->get());
        // Notify robots car is ready for work
        cradle->startWork();
        // Wait until work completes
        cradle->waitUntilWorkFinished();
        // Put car into queue for further work
        finishingQueue->put(cradle->getCar());
      }
    } catch(Interrupted_Exception&) { /* Exit */ }
    cout << "Director off" << endl;
  }
};

class EngineRobot : public Runnable {
  CradlePtr cradle;
public:
  EngineRobot(CradlePtr cr) : cradle(cr) {}
  void run() {
    try {
      while(!Thread::interrupted()) {
        // Blocks until job is offered/accepted:
        cradle->offerEngineBotServices();
        cout << "Installing engine" << endl;
        (*cradle)->addEngine();
        cradle->taskFinished();
      }
    } catch(Interrupted_Exception&) { /* Exit */ }
    cout << "EngineRobot off" << endl;
  }
};

class DriveTrainRobot : public Runnable {
  CradlePtr cradle;
public:
  DriveTrainRobot(CradlePtr cr) : cradle(cr) {}
  void run() {
    try {
      while(!Thread::interrupted()) {
        // Blocks until job is offered/accepted:
        cradle->offerDriveTrainBotServices();
        cout << "Installing DriveTrain" << endl;
        (*cradle)->addDriveTrain();
        cradle->taskFinished();
      }
    } catch(Interrupted_Exception&) { /* Exit */ }
    cout << "DriveTrainRobot off" << endl;
  }
};

class WheelRobot : public Runnable {
  CradlePtr cradle;
public:
  WheelRobot(CradlePtr cr) : cradle(cr) {}
  void run() {
    try {
      while(!Thread::interrupted()) {
        // Blocks until job is offered/accepted:
        cradle->offerWheelBotServices();
        cout << "Installing Wheels" << endl;
        (*cradle)->addWheels();
        cradle->taskFinished();
      }
    } catch(Interrupted_Exception&) { /* Exit */ }
    cout << "WheelRobot off" << endl;
  }
};

class Reporter : public Runnable {
  CarQueue carQueue;
public:
  Reporter(CarQueue& cq) : carQueue(cq) {}
  void run() {
    try {
      while(!Thread::interrupted()) {
        cout << carQueue->get() << endl;
      }
    } catch(Interrupted_Exception&) { /* Exit */ }
    cout << "Reporter off" << endl;
  }
};

int main() {
  cout << "Press <Enter> to quit" << endl;
  try {
    CarQueue chassisQueue(new TQueue<Car>),
             finishingQueue(new TQueue<Car>);
    CradlePtr cradle(new Cradle);
    ThreadedExecutor assemblyLine;
    assemblyLine.execute(new EngineRobot(cradle));
    assemblyLine.execute(new DriveTrainRobot(cradle));
    assemblyLine.execute(new WheelRobot(cradle));
    assemblyLine.execute(
      new Director(chassisQueue, finishingQueue, cradle));
    assemblyLine.execute(new Reporter(finishingQueue));
    // Start everything running by producing chassis:
    assemblyLine.execute(new ChassisBuilder(chassisQueue));
    cin.get();
    assemblyLine.interrupt();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
