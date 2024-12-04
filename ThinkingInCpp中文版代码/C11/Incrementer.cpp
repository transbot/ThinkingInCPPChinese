//: C11:Incrementer.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 在线程仍在运行时销毁对象会导致严重问题
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/ThreadedExecutor.h"

using namespace ZThread;
using namespace std;

class Count {
    enum { SZ = 100 };
    int n[SZ];
public:
    void increment() {
        for(int i = 0; i < SZ; i++)
            n[i]++;
    }
};

class Incrementer : public Runnable {
    Count* count;
public:
    Incrementer(Count* c) : count(c) {}
    void run() {
        for(int n = 100; n > 0; n--) {
            Thread::sleep(250);
            count->increment();
        }
    }
};

int main() {
    cout << "这将导致段错误！" << endl;
    Count count;
    try {
        // 两个线程共享同一个count对象
        Thread t0(new Incrementer(&count));
        Thread t1(new Incrementer(&count));
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
