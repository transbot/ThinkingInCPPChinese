//: C11:SleepingTask.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 调用sleep()以暂停一段时间
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/ThreadedExecutor.h"

using namespace ZThread;
using namespace std;

class SleepingTask : public Runnable {
    int countDown;
    int id;

public:
    SleepingTask(int ident = 0) : countDown(5), id(ident) {}
    ~SleepingTask() {
        cout << id << " 完成" << endl;
    }
    friend ostream& operator<<(ostream& os, const SleepingTask& st) {
        return os << "#" << st.id << ": " << st.countDown;
    }
    void run() {
        while(true) {
            try {
                cout << *this << endl;
                if(--countDown == 0) return;
                Thread::sleep(100); // 暂停100毫秒
            } catch(Interrupted_Exception& e) {
                cerr << e.what() << endl;
            }
        }
    }
};

int main() {
    try {
        ThreadedExecutor executor;
        for(int i = 0; i < 5; i++)
            executor.execute(new SleepingTask(i));
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
