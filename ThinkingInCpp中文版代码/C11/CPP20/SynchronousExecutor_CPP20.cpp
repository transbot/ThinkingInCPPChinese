// C11:SynchronousExecutor_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用现代C++标准库实现一个类似于SynchronousExecutor的功能
#include <iostream>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include "LiftOff_CPP20.h"

// SynchronousExecutor类，用于顺序执行任务
class SynchronousExecutor {
    std::queue<std::function<void()>> tasks; // 任务队列
    std::mutex mtx; // 互斥锁保护任务队列
    std::condition_variable cv; // 条件变量用于任务同步
    bool stop = false; // 终止标志
    bool done = false; // 任务完成标志

public:
    // 提交任务到执行器
    void execute(std::function<void()> task) {
        std::unique_lock<std::mutex> lock(mtx);
        tasks.push(std::move(task));
        cv.notify_one();
    }

    // 开始执行任务
    void run() {
        while (true) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this] { return !tasks.empty() || stop; });
                if (stop && tasks.empty()) {
                    done = true;
                    cv.notify_all(); // 通知主线程任务已完成
                    return; // 这里返回，结束循环
                }
                task = std::move(tasks.front());
                tasks.pop();
            }
            task();
        }
    }

    // 停止执行任务
    void shutdown() {
        std::unique_lock<std::mutex> lock(mtx);
        stop = true;
        cv.notify_all();
    }

    // 等待所有任务完成
    void waitForCompletion() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return done; });
    }
};

int main() {
    SynchronousExecutor executor;

    // 提交任务
    for (int i = 0; i < 5; ++i) {
        executor.execute([i]() {
            LiftOff liftOff(10, i);
            liftOff.run();
        });
    }

    // 在main线程中运行任务
    executor.run();

    // 设置停止标志
    executor.shutdown();

    // 等待所有任务完成
    executor.waitForCompletion();

    return 0;
}