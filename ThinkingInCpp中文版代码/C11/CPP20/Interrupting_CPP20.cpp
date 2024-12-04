//: C11:Interrupting_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 中断阻塞的线程
#include <iostream>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <chrono>

using namespace std;

class Blocked {
    // 原子变量，用于标记是否中断
    atomic<bool> interrupted;

    // 条件变量，用于线程间的通知
    condition_variable cv;

    // 互斥锁，用于保护共享数据
    mutex mtx;

public:
    // 构造函数，初始化中断标志为false
    Blocked() : interrupted(false) {}

    // 线程运行的主要函数
    void run() {
        try {
            // 模拟阻塞操作（等待1秒）
            {
                unique_lock<mutex> lock(mtx);
                // 如果在等待过程中被中断，则抛出异常
                if (cv.wait_for(lock, chrono::seconds(1)) == cv_status::no_timeout && interrupted.load()) {
                    throw runtime_error("捕获到Interrupted_Exception");
                }
            }

            // 输出提示信息，模拟进一步的阻塞操作（等待用户输入）
            cout << "在run()中等待cin.get():";
            {
                unique_lock<mutex> lock(mtx);
                // 如果在等待过程中被中断，则抛出异常
                if (cv.wait_for(lock, chrono::seconds(10)) == cv_status::no_timeout && interrupted.load()) {
                    throw runtime_error("捕获到Interrupted_Exception");
                }
            }
            // 等待用户输入
            cin.get();
        } catch (const runtime_error& e) {
            // 捕获到异常后输出信息，并退出任务
            cout << e.what() << endl;
        }
    }

    // 中断线程的函数
    void interrupt() {
        // 设置中断标志，并通知所有等待中的线程
        interrupted.store(true);
        cv.notify_all();
    }
};

int main(int argc, char* argv[]) {
    // 创建Blocked对象
    Blocked blocked;
    // 创建并启动线程，运行Blocked::run函数
    thread t(&Blocked::run, &blocked);

    // 如果提供了命令行参数，则主线程睡眠1.1秒
    if (argc > 1) {
        this_thread::sleep_for(chrono::milliseconds(1100));
    }

    // 中断线程
    blocked.interrupt();

    // 等待线程结束
    t.join();

    return 0;
}
