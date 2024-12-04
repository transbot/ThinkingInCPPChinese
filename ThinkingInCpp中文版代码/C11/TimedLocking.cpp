//: C11:TimedLocking.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 限时锁定
//{L} ZThread
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"

using namespace ZThread;

class TimedLocking {
    Mutex lock;
public:
    void f() {
        Guard<Mutex, TimedLockedScope<500> > g(lock); // ...
    }
};

int main() {
    TimedLocking t;
    t.f();
} ///:~
