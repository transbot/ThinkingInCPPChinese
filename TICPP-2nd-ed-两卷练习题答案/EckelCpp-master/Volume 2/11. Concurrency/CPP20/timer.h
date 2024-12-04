#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <mutex>
#include <condition_variable>

class Timer {
    std::atomic<bool> active;       // 用于控制定时器的激活状态
    std::thread timerThread;        // 定时器线程
    std::mutex mtx;                 // 互斥锁保护定时器状态
    std::condition_variable cv;     // 条件变量用于通知定时器停止

public:
    Timer() : active(false) {}

    ~Timer() {
        stop();  // 在析构函数中确保定时器停止
    }

    // 一次性定时器，只触发一次
    void once(int interval, std::function<void()> task) {
        if (active.load()) return;  // 如果定时器已经激活，直接返回
        active = true;
        timerThread = std::thread([=]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));  // 等待指定时间
            if (active.load()) {  // 检查定时器是否仍然激活
                task();  // 执行任务
            }
            stop();  // 任务完成后停止定时器
        });
    }

    // 定期触发的定时器
    void periodic(int interval, std::function<void()> task) {
        if (active.load()) return;  // 如果定时器已经激活，直接返回
        active = true;
        timerThread = std::thread([=]() {
            while (active.load()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));  // 等待指定时间
                if (active.load()) {  // 检查定时器是否仍然激活
                    task();  // 执行任务
                }
            }
        });
    }

    // 停止定时器
    void stop() {
        active = false;
        cv.notify_all();
        if (timerThread.joinable()) {
            timerThread.join();  // 等待定时器线程结束
        }
    }
};

#endif // TIMER_H
