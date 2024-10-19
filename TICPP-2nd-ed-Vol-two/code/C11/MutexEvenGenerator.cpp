//: C11:MutexEvenGenerator.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
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
