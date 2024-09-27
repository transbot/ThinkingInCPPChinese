//: C11:DiningPhilosophers.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Classes for Dining Philosophers.
#ifndef DININGPHILOSOPHERS_H
#define DININGPHILOSOPHERS_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "zthread/Condition.h"
#include "zthread/Guard.h"
#include "zthread/Mutex.h"
#include "zthread/Thread.h"
#include "Display.h"

class Chopstick {
  ZThread::Mutex lock;
  ZThread::Condition notTaken;
  bool taken;
public:
  Chopstick() : notTaken(lock), taken(false) {}
  void take() {
    ZThread::Guard<ZThread::Mutex> g(lock);
    while(taken)
      notTaken.wait();
    taken = true;
  }
  void drop() {
    ZThread::Guard<ZThread::Mutex> g(lock);
    taken = false;
    notTaken.signal();
  }
};

class Philosopher : public ZThread::Runnable {
  Chopstick& left;
  Chopstick& right;
  int id;
  int ponderFactor;
  ZThread::CountedPtr<Display> display;
  int randSleepTime() {
    if(ponderFactor == 0) return 0;
    return rand()/(RAND_MAX/ponderFactor) * 250;
  }
  void output(std::string s) {
    std::ostringstream os;
    os << *this << " " << s << std::endl;
    display->output(os);
  }
public:
  Philosopher(Chopstick& l, Chopstick& r,
  ZThread::CountedPtr<Display>& disp, int ident,int ponder)
  : left(l), right(r), id(ident), ponderFactor(ponder),
    display(disp) {}
  virtual void run() {
    try {
      while(!ZThread::Thread::interrupted()) {
        output("thinking");
        ZThread::Thread::sleep(randSleepTime());
        // Hungry
        output("grabbing right");
        right.take();
        output("grabbing left");
        left.take();
        output("eating");
        ZThread::Thread::sleep(randSleepTime());
        right.drop();
        left.drop();
      }
    } catch(ZThread::Synchronization_Exception& e) {
      output(e.what());
    }
  }
  friend std::ostream&
  operator<<(std::ostream& os, const Philosopher& p) {
    return os << "Philosopher " << p.id;
  }
};
#endif // DININGPHILOSOPHERS_H ///:~
