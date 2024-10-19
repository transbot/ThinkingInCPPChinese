//: C11:WaxOMatic.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Basic thread cooperation.
//{L} ZThread
#include <iostream>
#include <string>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include "zthread/Condition.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

class Car {
  Mutex lock;
  Condition condition;
  bool waxOn;
public:
  Car() : condition(lock), waxOn(false) {}
  void waxed() {
    Guard<Mutex> g(lock);
    waxOn = true; // Ready to buff
    condition.signal();
  }
  void buffed() {
    Guard<Mutex> g(lock);
    waxOn = false; // Ready for another coat of wax
    condition.signal();
  }
  void waitForWaxing() {
    Guard<Mutex> g(lock);
    while(waxOn == false)
      condition.wait();
  }
  void waitForBuffing() {
    Guard<Mutex> g(lock);
    while(waxOn == true)
      condition.wait();
  }
};

class WaxOn : public Runnable {
  CountedPtr<Car> car;
public:
  WaxOn(CountedPtr<Car>& c) : car(c) {}
  void run() {
    try {
      while(!Thread::interrupted()) {
        cout << "Wax On!" << endl;
        Thread::sleep(200);
        car->waxed();
        car->waitForBuffing();
      }
    } catch(Interrupted_Exception&) { /* Exit */ }
    cout << "Ending Wax On process" << endl;
  }
};

class WaxOff : public Runnable {
  CountedPtr<Car> car;
public:
  WaxOff(CountedPtr<Car>& c) : car(c) {}
  void run() {
    try {
      while(!Thread::interrupted()) {
        car->waitForWaxing();
        cout << "Wax Off!" << endl;
        Thread::sleep(200);
        car->buffed();
      }
    } catch(Interrupted_Exception&) { /* Exit */ }
    cout << "Ending Wax Off process" << endl;
  }
};

int main() {
  cout << "Press <Enter> to quit" << endl;
  try {
    CountedPtr<Car> car(new Car);
    ThreadedExecutor executor;
    executor.execute(new WaxOff(car));
    executor.execute(new WaxOn(car));
    cin.get();
    executor.interrupt();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
