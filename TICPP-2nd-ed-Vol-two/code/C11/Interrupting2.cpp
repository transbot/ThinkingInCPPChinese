//: C11:Interrupting2.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Interrupting a thread blocked
// with a synchronization guard.
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
using namespace ZThread;
using namespace std;

class BlockedMutex {
  Mutex lock;
public:
  BlockedMutex() {
    lock.acquire();
  }
  void f() {
    Guard<Mutex> g(lock);
    // This will never be available
  }
};

class Blocked2 : public Runnable {
  BlockedMutex blocked;
public:
  void run() {
    try {
      cout << "Waiting for f() in BlockedMutex" << endl;
      blocked.f();
    } catch(Interrupted_Exception& e) {
      cerr << e.what() << endl;
      // Exit the task
    }
  }
};

int main(int argc, char* argv[]) {
  try {
    Thread t(new Blocked2);
    t.interrupt();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
