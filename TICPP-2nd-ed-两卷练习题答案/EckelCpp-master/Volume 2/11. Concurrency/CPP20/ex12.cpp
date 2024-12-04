// 添加更多的Process类实例，使其应用并抛光三层蜡而不是一层。

// 基本的线程协作
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <atomic>
#include <vector>

class Car {
    std::mutex mtx;
    std::condition_variable condition;
    int layer; // 层数
public:
    Car() : layer(0) {}

    void waxed() {
        std::lock_guard<std::mutex> lock(mtx);
        layer++; // 增加一层蜡
        condition.notify_all();
    }

    void buffed() {
        std::lock_guard<std::mutex> lock(mtx);
        layer--; // 抛光去除一层蜡
        condition.notify_all();
    }

    void waitForWaxing(int targetLayer) { // 等待打蜡完成
        std::unique_lock<std::mutex> lock(mtx);
        condition.wait(lock, [this, targetLayer] { return layer == targetLayer; });
    }

    void waitForBuffing(int targetLayer) { // 等待抛光完成
        std::unique_lock<std::mutex> lock(mtx);
        condition.wait(lock, [this, targetLayer] { return layer == targetLayer; });
    }
};

class Process {
    Car& car;
    std::atomic<bool>& interrupted;
    int layer;
    bool isWaxOn;
public:
    Process(Car& c, std::atomic<bool>& interrupt, int l, bool waxOn)
        : car(c), interrupted(interrupt), layer(l), isWaxOn(waxOn) {}

    void operator()() {
        try {
            while (!interrupted.load()) {
                if (isWaxOn) {
                    std::cout << "正在打蜡第 " << layer << " 层!" << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    car.waxed();
                    car.waitForBuffing(layer);
                } else {
                    car.waitForWaxing(layer);
                    std::cout << "正在抛光第 " << layer << " 层!" << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    car.buffed();
                }
            }
        } catch (...) {
            // 捕获所有异常以终止进程
        }
        if (isWaxOn) {
            std::cout << "结束打蜡过程第 " << layer << " 层" << std::endl;
        } else {
            std::cout << "结束抛光过程第 " << layer << " 层" << std::endl;
        }
    }
};

int main() {
    std::cout << "请按<Enter>键退出" << std::endl;
    try {
        Car car;
        std::atomic<bool> interrupted(false);
        std::vector<std::thread> threads;

        for (int i = 1; i <= 3; ++i) { // 为三层打蜡和抛光创建线程
            threads.emplace_back(Process(car, interrupted, i, true)); // 打蜡线程
            threads.emplace_back(Process(car, interrupted, i, false)); // 抛光线程
        }

        // 等待用户按<Enter>键
        std::cin.get();
        interrupted.store(true);

        for (auto& t : threads) {
            t.join();
        }
    } catch (const std::exception& e) {
        std::cerr << "异常: " << e.what() << std::endl;
    }
    std::cout << "正在关闭..." << std::endl;
    return 0;
}
