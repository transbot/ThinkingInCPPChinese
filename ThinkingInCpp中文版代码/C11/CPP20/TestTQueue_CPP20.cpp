//: C11:TestTQueue_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "TQueue_CPP20.h"
#include "LiftOff_CPP20.h"

using namespace std;

// LiftOffRunner从TQueue中取出每个LiftOff对象并直接运行
class LiftOffRunner : public Runnable {
    TQueue<LiftOff*> rockets;
    atomic<bool> interrupted{false};

public:
    void add(LiftOff* lo) {
        rockets.put(lo);
    }

    void run() override {
        try {
            while (!interrupted.load()) {
                LiftOff* rocket = rockets.get();
                rocket->run();
            }
        } catch (const runtime_error&) {
            // 退出
        }
        cout << "退出LiftOffRunner" << endl;
    }

    void interrupt() {
        interrupted.store(true);
    }
};

int main() {
    LiftOffRunner lor;

    // 创建并启动线程，运行LiftOffRunner的run方法
    thread t(&LiftOffRunner::run, &lor);

    for (int i = 0; i < 5; i++)
        lor.add(new LiftOff(10, i));

    cin.get(); // 按下<Enter>后添加继续添加一个LiftOff对象
    lor.add(new LiftOff(10, 99));
    cin.get(); // 再按下<Enter>中断线程并等待线程结束
    lor.interrupt();
    t.join();

    return 0;
}
