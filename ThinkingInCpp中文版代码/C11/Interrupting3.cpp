//: C11:Interrupting3.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 中断任务时采取的惯用法
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

const double PI = 3.14159265358979323846;
const double E = 2.7182818284590452354;

class NeedsCleanup {
    int id;
public:
    NeedsCleanup(int ident) : id(ident) {
        cout << "NeedsCleanup " << id << endl;
    }
    ~NeedsCleanup() {
        cout << "~NeedsCleanup " << id << endl;
    }
};

class Blocked3 : public Runnable {
    volatile double d;
public:
    Blocked3() : d(0.0) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                point1:  // 位置1
                NeedsCleanup n1(1);
                cout << "正在睡眠" << endl;
                Thread::sleep(1000);
                point2:  // 位置2
                NeedsCleanup n2(2);
                cout << "正在计算" << endl;
                // 一个耗时的非阻塞操作：
                for(int i = 1; i < 100000; i++)
                    d = d + (PI + E) / (double)i;
            }
            cout << "通过while()测试退出" << endl;
        } catch(Interrupted_Exception&) {
            cout << "通过捕获Interrupted_Exception退出" << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cerr << "用法: " << argv[0] << " 延迟毫秒数" << endl;
        exit(1);
    }
    int delay = atoi(argv[1]);
    try {
        Thread t(new Blocked3);
        Thread::sleep(delay);
        t.interrupt();
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
