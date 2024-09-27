//: C11:GuardedEvenGenerator.cpp {RunByHand}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Simplifying mutexes with the Guard template.
//{L} ZThread
#include <iostream>
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
using namespace ZThread;
using namespace std;

class GuardedEvenGenerator : public Generator {
  unsigned int currentEvenValue;
  Mutex lock;
public:
  GuardedEvenGenerator() { currentEvenValue = 0; }
  ~GuardedEvenGenerator() {
    cout << "~GuardedEvenGenerator" << endl;
  }
  int nextValue() {
    Guard<Mutex> g(lock);
    ++currentEvenValue;
    Thread::yield();
    ++currentEvenValue;
    return currentEvenValue;
  }
};

int main() {
  EvenChecker::test<GuardedEvenGenerator>();
} ///:~
