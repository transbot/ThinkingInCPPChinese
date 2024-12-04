//: C11:Interrupting3_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 中断任务时采取的惯用法
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <cstdlib>
#include <condition_variable>
#include <mutex>

using namespace std;

const double PI = 3.14159265358979323846;
const double E = 2.7182818284590452354;

// NeedsCleanup类，用于模拟资源清理
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

// Blocked3类，模拟可以被中断的任务
class Blocked3 {
    atomic<bool> interrupted; // 中断标志
    volatile double d; // 计算变量
    mutex mtx;
    condition_variable cv;

public:
    Blocked3() : interrupted(false), d(0.0) {}

    void run() {
        try {
            while (!interrupted.load()) {
                NeedsCleanup n1(1);
                cout << "正在睡眠" << endl;
                {
                    unique_lock<mutex> lock(mtx);
                    if (cv.wait_for(lock, chrono::seconds(1), [this] { return interrupted.load(); })) {
                        throw runtime_error("通过捕获Interrupted_Exception退出");
                    }
                }

                NeedsCleanup n2(2);
                cout << "正在计算" << endl;
                // 一个耗时的非阻塞操作
                for (int i = 1; i < 100000; i++)
                    d = d + (PI + E) / (double)i;
            }
            cout << "通过while()测试退出" << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    void interrupt() {
        interrupted.store(true);
        cv.notify_all(); // 通知条件变量，确保阻塞的wait操作解除
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "用法: " << argv[0] << " 延迟毫秒数" << endl;
        exit(1);
    }
    int delay = atoi(argv[1]);

    Blocked3 blocked3;

    // 创建并启动线程，运行Blocked3::run函数
    thread t(&Blocked3::run, &blocked3);

    // 主线程睡眠指定的毫秒数
    this_thread::sleep_for(chrono::milliseconds(delay));

    // 中断线程
    blocked3.interrupt();

    // 等待线程结束
    t.join();

    return 0;
}
