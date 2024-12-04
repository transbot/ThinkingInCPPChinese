//: C11:DeadlockingDiningPhilosophers_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 存在死锁可能的就餐哲学家问题
#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "DiningPhilosophers_CPP20.h"
using namespace std;

int main(int argc, char* argv[]) {
    // 初始化随机数生成器
    srand(static_cast<unsigned>(time(0)));

    // 获取命令行参数，设置哲学家思考的时间因子
    int ponder = (argc > 1) ? atoi(argv[1]) : 5;
    cout << "请按<ENTER>键退出" << endl;

    // 定义常量，表示哲学家的数量
    const int NUM_PHILOSOPHERS = 5;

    try {        
        // 创建显示对象
        auto display = make_shared<Display>();

        // 创建筷子数组
        vector<Chopstick> chopsticks(NUM_PHILOSOPHERS);

        // 创建哲学家数组，并启动他们的线程
        vector<shared_ptr<Philosopher>> philosophers;
        for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
            // 创建哲学家对象
            auto philosopher = make_shared<Philosopher>(
                chopsticks[i], chopsticks[(i + 1) % NUM_PHILOSOPHERS],
                display, i, ponder
            );

            // 启动哲学家线程
            philosopher->start();

            // 将哲学家添加到向量中
            philosophers.push_back(philosopher);
        }

        // 等待用户按下Enter键
        cin.get();

        // 请求所有哲学家线程停止
        for (auto& philosopher : philosophers) {
            philosopher->request_stop();
        }

        // 主线程等待一段时间，确保所有哲学家线程有足够的时间退出
        this_thread::sleep_for(chrono::seconds(1));

        // 输出结束信息
        cout << "所有哲学家已退出" << endl;

    } catch (const exception& e) {
        cerr << "异常: " << e.what() << endl;
    }

    return 0;
}
