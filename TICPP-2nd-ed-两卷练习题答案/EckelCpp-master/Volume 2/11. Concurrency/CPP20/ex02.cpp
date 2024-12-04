#include <iostream>
#include <thread>
#include <vector>
#include "LiftOff_CPP20.h"

// 在这个修改后的程序中：
// 我们首先创建了一个初始的LiftOff对象，并用一个线程执行它的run方法。
// 然后我们创建了一个extraThreads向量，用于存储额外的LiftOff 线程。每个新线程执行一个新的LiftOff对象的run方法，并将这些线程添加到向量中。
// 主线程等待初始的LiftOff线程完成后，等待所有额外的LiftOff线程完成。
using namespace std;

int main() {
    try {
        // 创建一个LiftOff对象，倒计时10次，任务标识符默认为0
        LiftOff liftoff(10);
        // 创建一个线程，执行LiftOff对象的run方法
        std::thread t(&LiftOff::run, &liftoff);
        cout << "点火倒计时" << endl; // 打印等待消息

        // 创建并启动额外的LiftOff线程
        vector<std::thread> extraThreads;
        for (int i = 1; i <= 3; ++i) {
            extraThreads.emplace_back(&LiftOff::run, new LiftOff(10, i));
        }

        // 等待初始线程结束
        t.join();

        // 等待所有额外的LiftOff线程结束
        for (auto& t : extraThreads) {
            if (t.joinable()) {
                t.join();
            }
        }

    } catch (const std::exception& e) {
        // 捕获并打印异常
        cerr << "异常: " << e.what() << endl;
    }
    return 0;
}
