// C11:ConcurrentExecutor_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用现代C++标准库实现类似于ZThread::ConcurrentExecutor的功能
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include "LiftOff_CPP20.h"

using namespace std;

class ConcurrentExecutor {
private:
    thread worker;
    queue<function<void()>> tasks;
    mutex queue_mutex;
    condition_variable condition;
    bool stop;

public:
    ConcurrentExecutor() : stop(false) {
        worker = thread([this] {
            while(true) {
                function<void()> task;
                {
                    unique_lock<mutex> lock(this->queue_mutex);
                    this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); });
                    if(this->stop && this->tasks.empty())
                        break;
                    task = move(this->tasks.front());
                    this->tasks.pop();
                }
                task(); // 执行任务
            }
        });
    }

    ~ConcurrentExecutor() {
        {
            unique_lock<mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        worker.join(); // 等待工作线程结束
    }

    void execute(Runnable* task) {
        {
            unique_lock<mutex> lock(queue_mutex);
            if(stop)
                throw runtime_error("execute on stopped ConcurrentExecutor");
            tasks.emplace([task] {
                task->run();
                delete task; // 释放任务对象
            });
        }
        condition.notify_one(); // 通知工作线程
    }
};

int main() {
    try {
        ConcurrentExecutor executor; // 创建一个ConcurrentExecutor对象
        for(int i = 0; i < 5; i++) {
            executor.execute(new LiftOff(10, i)); // 提交5个LiftOff任务
        }
    } catch(const exception& e) {
        cerr << "异常: " << e.what() << endl; // 捕获并打印异常
    }
    cout << "所有任务已完成" << endl; // 打印所有任务完成的消息
    return 0;
}