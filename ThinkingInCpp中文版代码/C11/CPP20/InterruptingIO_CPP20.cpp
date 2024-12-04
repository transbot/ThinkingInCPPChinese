//: C11:InterruptingIO_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 现代C++如何在执行I/O期间退出
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<bool> terminate_thread(false);

void io_task() {
    while (!terminate_thread.load()) {
        // 模拟I/O操作
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "正在执行I/O操作" << std::endl;

        // 定期检查是否需要终止线程
        if (terminate_thread.load()) {
            std::cout << "正在终止执行I/O的线程" << std::endl;
            break;
        }
    }
}

int main() {
    std::thread t(io_task);
    std::this_thread::sleep_for(std::chrono::seconds(2));  // 模拟主线程的其他工作    
    std::cout << "请求线程终止" << std::endl;
    terminate_thread.store(true);  // 发出终止请求

    t.join();  // 等待线程结束

    std::cout << "线程已终止" << std::endl;
    return 0;
}
