//: C11:WaxOMatic_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 基本的线程协作
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <atomic>

class Car {
    std::mutex mtx;
    std::condition_variable condition;
    bool waxOn;
public:
    Car() : waxOn(false) {}

    void waxed() {
        std::lock_guard<std::mutex> lock(mtx);
        waxOn = true; // 打蜡完成，准备好抛光
        condition.notify_all();
    }

    void buffed() {
        std::lock_guard<std::mutex> lock(mtx);
        waxOn = false; // 抛光完成，已准备好再涂一层蜡
        condition.notify_all();
    }

    void waitForWaxing() { // 等待打蜡完成
        std::unique_lock<std::mutex> lock(mtx);
        condition.wait(lock, [this] { return waxOn; });
    }

    void waitForBuffing() { // 等待抛光完成
        std::unique_lock<std::mutex> lock(mtx);
        condition.wait(lock, [this] { return !waxOn; });
    }
};

class WaxOn {
    Car& car;
    std::atomic<bool>& interrupted;
public:
    WaxOn(Car& c, std::atomic<bool>& interrupt) : car(c), interrupted(interrupt) {}

    void operator()() {
        try {
            while (!interrupted.load()) {
                std::cout << "正在打蜡!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                car.waxed();
                car.waitForBuffing();
            }
        } catch (...) {
            // 捕获所有异常以终止进程
        }
        std::cout << "结束打蜡过程" << std::endl;
    }
};

class WaxOff {
    Car& car;
    std::atomic<bool>& interrupted;
public:
    WaxOff(Car& c, std::atomic<bool>& interrupt) : car(c), interrupted(interrupt) {}

    void operator()() {
        try {
            while (!interrupted.load()) {
                car.waitForWaxing();
                std::cout << "正在抛光!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                car.buffed();
            }
        } catch (...) {
            // 捕获所有异常以终止进程
        }
        std::cout << "结束抛光过程" << std::endl;
    }
};

int main() {
    std::cout << "请按<Enter>键退出" << std::endl;
    try {
        Car car;
        std::atomic<bool> interrupted(false);
        std::thread waxOffThread(WaxOff(car, interrupted));
        std::thread waxOnThread(WaxOn(car, interrupted));

        // 等待用户按<Enter>键
        std::cin.get();
        interrupted.store(true);

        waxOnThread.join();
        waxOffThread.join();
    } catch (const std::exception& e) {
        std::cerr << "异常: " << e.what() << std::endl;
    }
    std::cout << "正在关闭..." << std::endl;
    return 0;
}
