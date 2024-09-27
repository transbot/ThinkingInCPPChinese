//: C11:TimedLocking.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Limited time locking.
//{L} ZThread
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
using namespace ZThread;

class TimedLocking {
  Mutex lock;
public:
  void f() {
    Guard<Mutex, TimedLockedScope<500> > g(lock);
    // ...
  }
};

int main() {
  TimedLocking t;
  t.f();
} ///:~
