//: C11:Interrupting2_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 中断被同步保护阻塞的线程
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

// 模拟被阻塞的互斥锁
class BlockedMutex {
    mutex mtx;
    atomic<bool> acquired;

public:
    BlockedMutex() : acquired(false) {
        mtx.lock();
        acquired = true;
    }

    void f() {
        // 试图获取互斥锁，但由于锁已经被获取，因此会一直阻塞
        lock_guard<mutex> g(mtx);
    }

    bool isAcquired() const {
        return acquired;
    }

    void release() {
        if (acquired) {
            mtx.unlock();
            acquired = false;
        }
    }
};

// 模拟运行中阻塞的线程
class Blocked2 {
    BlockedMutex blocked;

public:
    void run() {
        try {
            cout << "等待BlockedMutex中的f()" << endl;
            blocked.f();
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
            // 退出任务
        }
    }

    void interrupt() {
        blocked.release();
    }
};

int main(int argc, char* argv[]) {
    Blocked2 blocked2;

    // 创建并启动线程，运行Blocked2::run函数
    thread t(&Blocked2::run, &blocked2);

    // 模拟一些工作
    if (argc > 1) {
        this_thread::sleep_for(chrono::milliseconds(1100));
    }

    // 中断线程
    blocked2.interrupt();

    // 等待线程结束
    t.join();

    return 0;
}
