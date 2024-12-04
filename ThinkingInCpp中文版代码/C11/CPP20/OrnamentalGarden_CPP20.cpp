//: C11:OrnamentalGarden_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 在这个模拟中，花园的管理层希望知道每天有多少人通过其多个入口入园。
// 每个入口都有一个旋转栅门或其他类型的计数器。当旋转栅门计数递增后，
// 还会递增一个代表花园内总人数的共享计数。

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include "Display_CPP20.h"

class Count {
    std::mutex lock;
    int count;
    std::atomic<bool> paused, canceled;

public:
    Count() : count(0), paused(false), canceled(false) {}

    int increment() {
        std::lock_guard<std::mutex> g(lock);
        int temp = count;
        if (rand() % 2 == 0) {
            std::this_thread::yield(); // 半数时间让出CPU
        }
        return count = ++temp;
    }

    int value() {
        std::lock_guard<std::mutex> g(lock);
        return count;
    }

    void cancel() {
        std::lock_guard<std::mutex> g(lock);
        canceled = true;
    }

    bool isCanceled() const {
        return canceled.load();
    }

    void pause() {
        std::lock_guard<std::mutex> g(lock);
        paused = true;
    }

    bool isPaused() const {
        return paused.load();
    }
};

class Entrance {
    Count& count;
    Display& display;
    int number;
    int id;
    std::atomic<bool> waitingForCancel;

public:
    Entrance(Count& cnt, Display& disp, int idn)
        : count(cnt), display(disp), number(0), id(idn), waitingForCancel(false) {}

    void operator()() {
        while (!count.isPaused()) {
            ++number;
            {
                std::ostringstream os;
                os << *this << " 总人数: " << count.increment() << std::endl;
                display.output(os);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        waitingForCancel = true;
        while (!count.isCanceled()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        std::ostringstream os;
        os << "正在终止 " << *this << std::endl;
        display.output(os);
    }

    int getValue() {
        while (count.isPaused() && !waitingForCancel.load()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        return number;
    }

    friend std::ostream& operator<<(std::ostream& os, const Entrance& e) {
        return os << "入口 " << e.id << ": " << e.number;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));  // 初始化随机数生成器
    std::cout << "请按<ENTER>键退出" << std::endl;

    Count count;
    Display display;
    const int SZ = 5;
    std::vector<std::thread> threads;
    std::vector<std::unique_ptr<Entrance>> entrances;

    // 创建并启动入口线程
    for (int i = 0; i < SZ; ++i) {
        entrances.push_back(std::make_unique<Entrance>(count, display, i));
        threads.emplace_back(std::ref(*entrances.back()));
    }

    // 等待用户按<Enter>键
    std::cin.get();
    count.pause();  // 停止任务计数

    // 计算并显示总人数
    int sum = 0;
    for (auto& entrance : entrances) {
        sum += entrance->getValue();
    }

    std::ostringstream os;
    os << "总人数: " << count.value() << std::endl
        << "所有入口人数之和: " << sum << std::endl;
    display.output(os);

    // 取消所有入口并等待线程结束
    count.cancel();
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    return 0;
}
