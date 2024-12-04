//: C11:TimedLocking_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用unique_lock来获取一个timed_mutex，尝试在指定时间内获取锁
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <stdexcept>

class TimedLocking {
    std::timed_mutex mtx;
public:
    void f() {
        std::unique_lock<std::timed_mutex> lock(mtx, std::defer_lock);
        const auto timeout = std::chrono::milliseconds(500);

        if (!lock.try_lock_for(timeout)) {
            // 超时处理，抛出运行时 异常
            throw std::runtime_error("500ms内未获得锁");
        }

        // 开始临界区代码
        // ...
        // 结束临界区代码
    }
};

int main() {
    TimedLocking t;
    try {
        t.f();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}