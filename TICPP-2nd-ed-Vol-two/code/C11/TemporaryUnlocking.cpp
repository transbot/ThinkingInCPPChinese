//: C11:TemporaryUnlocking.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
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
