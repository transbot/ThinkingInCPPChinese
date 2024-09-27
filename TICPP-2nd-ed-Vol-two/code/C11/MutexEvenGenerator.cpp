//: C11:MutexEvenGenerator.cpp {RunByHand}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Preventing thread collisions with mutexes.
//{L} ZThread
#include <iostream>
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/Mutex.h"
using namespace ZThread;
using namespace std;

class MutexEvenGenerator : public Generator {
  unsigned int currentEvenValue;
  Mutex lock;
public:
  MutexEvenGenerator() { currentEvenValue = 0; }
  ~MutexEvenGenerator() {
    cout << "~MutexEvenGenerator" << endl;
  }
  int nextValue() {
    lock.acquire();
    ++currentEvenValue;
    Thread::yield(); // Cause failure faster
    ++currentEvenValue;
    int rval = currentEvenValue;
    lock.release();
    return rval;
  }
};

int main() {
  EvenChecker::test<MutexEvenGenerator>();
} ///:~
