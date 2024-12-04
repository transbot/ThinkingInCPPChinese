//: C11:ReferenceCounting_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用shared_ptr智能指针防止过早销毁
// 使用互斥锁来保护共享数据，防止多个线程同时访问
// 现在，程序始终生成正确的结果：2000000
#include <thread>
#include <mutex>
#include <memory>
#include <iostream>

class Count {
public:
    int n = 0;
    std::mutex mtx;
    void increment() {
        std::lock_guard<std::mutex> lock(mtx);
        n++;
    }
};

int main() {
    std::shared_ptr<Count> count = std::make_shared<Count>();
    std::thread t1([](std::shared_ptr<Count> c) {
        for (int i = 0; i < 1000000; ++i) {
            c->increment();
        }
    }, count);
    std::thread t2([](std::shared_ptr<Count> c) {
        for (int i = 0; i < 1000000; ++i) {
            c->increment();
        }
    }, count);

    t1.join();
    t2.join();

    std::cout << count->n << std::endl;
    return 0;
}