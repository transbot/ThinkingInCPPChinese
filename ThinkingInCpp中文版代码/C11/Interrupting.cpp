//: C11:Interrupting.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 中断阻塞的线程
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

class Blocked : public Runnable {
public:
    void run() {
        try {
            Thread::sleep(1000);
            cout << "在run()中等待cin.get():";
            cin.get();
        } catch(Interrupted_Exception&) {
            cout << "捕获到Interrupted_Exception" << endl;
            // 退出任务
        }
    }
};

int main(int argc, char* argv[]) {
    try {
        Thread t(new Blocked);
        if(argc > 1)
            Thread::sleep(1100);
        t.interrupt();
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
