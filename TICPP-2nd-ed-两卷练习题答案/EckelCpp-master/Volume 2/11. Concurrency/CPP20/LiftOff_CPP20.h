// C11:LiftOff_CPP20.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#ifndef LIFTOFF_H
#define LIFTOFF_H

#include <iostream>
#include "Runnable_CPP20.h"
#include <thread> // 用于模拟延时
#include <mutex>  // 用于同步输出

// LiftOff类继承自Runnable，实现了一个火箭点火倒计时任务
class LiftOff : public Runnable {
private:
    int countDown; // 倒计时次数
    int id;        // 任务标识符
    static std::mutex coutMutex; // 静态互斥锁，用于同步std::cout

public:
    // 构造函数，初始化倒计时次数和任务标识符
    LiftOff(int count, int ident = 0) : countDown(count), id(ident) {}
    // 析构函数，打印任务完成的消息
    ~LiftOff() override {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << id << " 完成" << std::endl;
        
    }
    // 实现run方法，执行倒计时任务
    void run() override {
        while(countDown--) {
            {
                std::lock_guard<std::mutex> lock(coutMutex);
                std::cout << id << ":" << countDown << std::endl; // 打印当前倒计时
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 模拟延时
        }
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "点火!" << std::endl; // 倒计时结束，打印点火消息
        }
    }
};

// 初始化静态成员变量
std::mutex LiftOff::coutMutex;

#endif // LIFTOFF_H  ///:~