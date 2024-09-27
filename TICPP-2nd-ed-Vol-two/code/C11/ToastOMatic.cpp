//: C11:ToastOMatic.cpp {RunByHand}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Problems with thread cooperation.
//{L} ZThread
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include "zthread/Condition.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

// Apply jam to buttered toast:
class Jammer : public Runnable {
  Mutex lock;
  Condition butteredToastReady;
  bool gotButteredToast;
  int jammed;
public:
  Jammer() : butteredToastReady(lock) {
    gotButteredToast = false;
    jammed = 0;
  }
  void moreButteredToastReady() {
    Guard<Mutex> g(lock);
    gotButteredToast = true;
    butteredToastReady.signal();
  }
  void run() {
    try {
      while(!Thread::interrupted()) {
        {
          Guard<Mutex> g(lock);
          while(!gotButteredToast)
            butteredToastReady.wait();
          ++jammed;
        }
        cout << "Putting jam on toast " << jammed << endl;
        {
          Guard<Mutex> g(lock);
          gotButteredToast = false;
        }
      }
    } catch(Interrupted_Exception&) { /* Exit */ }
    cout << "Jammer off" << endl;
  }
};

// Apply butter to toast:
class Butterer : public Runnable {
  Mutex lock;
  Condition toastReady;
  CountedPtr<Jammer> jammer;
  bool gotToast;
  int buttered;
public:
  Butterer(CountedPtr<Jammer>& j)
  : toastReady(lock), jammer(j) {
    gotToast = false;
    buttered = 0;
  }
  void moreToastReady() {
    Guard<Mutex> g(lock);
    gotToast = true;
    toastReady.signal();
  }
  void run() {
    try {
      while(!Thread::interrupted()) {
        {
          Guard<Mutex> g(lock);
          while(!gotToast)
            toastReady.wait();
          ++buttered;
        }
        cout << "Buttering toast " << buttered << endl;
        jammer->moreButteredToastReady();
        {
          Guard<Mutex> g(lock);
          gotToast = false;
        }
      }
    } catch(Interrupted_Exception&) { /* Exit */ }
    cout << "Butterer off" << endl;
  }
};

class Toaster : public Runnable {
  CountedPtr<Butterer> butterer;
  int toasted;
public:
  Toaster(CountedPtr<Butterer>& b) : butterer(b) {
    toasted = 0;
  }
  void run() {
    try {
      while(!Thread::interrupted()) {
        Thread::sleep(rand()/(RAND_MAX/5)*100);
        // ...
        // Create new toast
        // ...
        cout << "New toast " << ++toasted << endl;
        butterer->moreToastReady();
      }
    } catch(Interrupted_Exception&) { /* Exit */ }
    cout << "Toaster off" << endl;
  }
};

int main() {
  srand(time(0)); // Seed the random number generator
  try {
    cout << "Press <Return> to quit" << endl;
    CountedPtr<Jammer> jammer(new Jammer);
    CountedPtr<Butterer> butterer(new Butterer(jammer));
    ThreadedExecutor executor;
    executor.execute(new Toaster(butterer));
    executor.execute(butterer);
    executor.execute(jammer);
    cin.get();
    executor.interrupt();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
