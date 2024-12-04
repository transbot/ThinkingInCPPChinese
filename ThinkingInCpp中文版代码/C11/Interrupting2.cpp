//: C11:Interrupting2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 中断被同步保护阻塞的线程
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
        Guard<Mutex> g(lock); // 这个永远不可用
    }
};

class Blocked2 : public Runnable {
    BlockedMutex blocked;
public:
    void run() {
        try {
            cout << "等待BlockedMutex中的f()" << endl;
            blocked.f();
        } catch(Interrupted_Exception& e) {
            cerr << e.what() << endl;
            // 退出任务
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
