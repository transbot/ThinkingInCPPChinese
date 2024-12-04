// C11:PoolExecutor_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用现代C++标准库实现一个简单的线程池
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include "LiftOff_CPP20.h"

using namespace std;

class PoolExecutor {
private:
    vector<thread> workers; // 存储工作线程的向量
    queue<function<void()>> tasks; // 存储任务的队列
    mutex queue_mutex; // 保护任务队列的互斥锁
    condition_variable condition; // 条件变量，用于线程间的同步
    bool stop; // 布尔标志，表示线程池是否停止

public:
    // 构造函数，初始化线程池
    PoolExecutor(size_t num_threads) : stop(false) {
        for(size_t i = 0; i < num_threads; ++i) {
            workers.emplace_back([this] {
                while(true) {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(this->queue_mutex); // 获取互斥锁
                        this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); }); // 等待任务或停止信号
                        if(this->stop && this->tasks.empty())
                            break; // 如果线程池停止且任务队列为空，则退出循环
                        task = move(this->tasks.front()); // 取出任务
                        this->tasks.pop(); // 从任务队列中移除任务
                    }
                    task(); // 执行任务
                }
            });
        }
    }

    // 析构函数，确保所有线程在对象销毁时都已结束
    ~PoolExecutor() {
        {
            unique_lock<mutex> lock(queue_mutex); // 获取互斥锁
            stop = true; // 设置停止标志
        }
        condition.notify_all(); // 通知所有等待的线程
        for(thread& worker : workers)
            worker.join(); // 等待所有工作线程结束
    }

    // 提交任务到线程池
    void execute(Runnable* task) {
        {
            unique_lock<mutex> lock(queue_mutex); // 获取互斥锁
            if(stop)
                throw runtime_error("在已停止的PoolExecutor上执行"); // 如果线程池已停止，抛出异常
            tasks.emplace([task] {
                task->run(); // 执行任务
                delete task; // 释放任务对象
            });
        }
        condition.notify_one(); // 通知一个等待的线程
    }
};

int main() {
    try {
        PoolExecutor executor(5); // 创建一个包含5个线程的线程池
        for(int i = 0; i < 5; i++) {
            executor.execute(new LiftOff(10, i)); // 提交5个LiftOff任务
        }
    } catch(const exception& e) {
        cerr << "异常: " << e.what() << endl; // 捕获并打印异常
    }
    cout << "所有任务已完成" << endl; // 打印所有任务完成的消息
    return 0;
}