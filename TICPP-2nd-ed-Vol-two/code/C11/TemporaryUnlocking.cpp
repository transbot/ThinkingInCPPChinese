//: C11:TemporaryUnlocking.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Temporarily unlocking another guard.
//{L} ZThread
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
using namespace ZThread;

class TemporaryUnlocking {
  Mutex lock;
public:
  void f() {
    Guard<Mutex> g(lock);
    // lock is acquired
    // ...
    {
      Guard<Mutex, UnlockedScope> h(g);
      // lock is released
      // ...
      // lock is acquired
    }
    // ...
    // lock is released
  }
};

int main() {
  TemporaryUnlocking t;
  t.f();
} ///:~
