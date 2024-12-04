//: C11:DiningPhilosophers_CPP20.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#ifndef DININGPHILOSOPHERS_H
#define DININGPHILOSOPHERS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <exception>
#include <chrono>
#include <memory>
#include <thread>
#include <sstream>
#include <atomic>
#include "Display_CPP20.h"


// 筷子类：表示一根筷子，哲学家需要同时持有两根筷子才能吃饭
class Chopstick {
    std::mutex lock;                        // 互斥锁，用于保护对筷子的访问
    std::condition_variable notTaken;       // 条件变量，用于通知等待的哲学家筷子是否可用
    bool taken = false;                     // 标记筷子是否已经被占用

public:
    // 构造函数，初始化筷子为未被占用状态
    Chopstick() = default;

    // take()方法：哲学家尝试拿起筷子
    void take() {
        std::unique_lock<std::mutex> lk(lock);  // 获取互斥锁，确保线程安全
        while (taken) {                         // 如果筷子已经被占用，等待
            notTaken.wait(lk);                  // 等待条件变量，直到筷子可用
        }
        taken = true;                           // 标记筷子已被占用
    }

    // drop()方法：哲学家放下筷子
    void drop() {
        std::unique_lock<std::mutex> lk(lock);  // 获取互斥锁，确保线程安全
        taken = false;                          // 标记筷子已释放
        notTaken.notify_one();                  // 通知等待的哲学家筷子现在可用
    }
};

// 哲学家类：表示一个哲学家，负责思考、拿筷子、吃饭和放筷子
class Philosopher : public std::enable_shared_from_this<Philosopher> {
    Chopstick& left;                            // 左边的筷子
    Chopstick& right;                           // 右边的筷子
    int id;                                     // 哲学家的编号
    int ponderFactor;                           // 思考时间的随机因子
    std::shared_ptr<Display> display;           // 用于输出信息的Display对象
    std::atomic<bool> should_stop{false};       // 中断标志位

public:
    // 设置中断标志位
    void request_stop() {
        should_stop.store(true);
    }

    // 构造函数，初始化哲学家的左右筷子、编号、思考因子和显示对象
    Philosopher(Chopstick& l, Chopstick& r, 
                std::shared_ptr<Display> disp, 
                int ident, int ponder)
        : left(l), right(r), id(ident), ponderFactor(ponder),
          display(disp) {}

    // 生成随机的思考或吃饭时间（以毫秒为单位）
    int randSleepTime() {
        if (ponderFactor == 0) return 0;           // 如果因子为0，返回0
        return (rand() % ponderFactor + 1) * 250;  // 生成随机时间
    }

    // 输出信息到显示对象
    void output(std::string s) {
        std::ostringstream os;
        os << *this << " " << s << std::endl;   // 构建输出字符串
        display->output(os);                    // 将信息输出到显示对象
    }

    // run()方法：哲学家的行为循环
    void run() {
        try {
            while (!should_stop.load()) {  // 检查是否收到中断请求
                output("正在思考...");
                std::this_thread::sleep_for(std::chrono::milliseconds(randSleepTime())); // 随机思考一段时间

                // 饿了，准备拿筷子
                output("拿右边的筷子");
                right.take();
                output("拿左边的筷子");
                left.take();

                output("吃饭");
                std::this_thread::sleep_for(std::chrono::milliseconds(randSleepTime()));

                // 吃完饭，放下筷子
                right.drop();
                left.drop();
            }
            output("哲学家 " + std::to_string(id) + " 退出");
        } catch (const std::exception& e) {
            output(e.what());  // 捕获并输出异常
        }
    }

    // 重载<<操作符，用于输出哲学家的信息
    friend std::ostream& operator<<(std::ostream& os, const Philosopher& p) {
        return os << "哲学家 " << p.id;  // 输出哲学家的编号
    }

    // 运行哲学家线程的方法
    void start() {
        std::thread([self = this->shared_from_this()] {
            self->run();
        }).detach();  // 分离线程，让其独立运行
    }
};
#endif // DININGPHILOSOPHERS_H ///:~

