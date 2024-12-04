//: C11:ThreadLocalVariables_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 自动为每个线程分配自己的存储
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <atomic> // 原子操作

using namespace std;

// 定义一个类，用于管理线程局部变量
class ThreadLocalVariables {
    thread_local static int value; // 线程局部变量，每个线程有自己的副本
    atomic<bool> canceled; // 原子布尔变量，用于取消操作

public:
    ThreadLocalVariables() : canceled(false) {
        value = 0; // 初始化线程局部变量
    }

    void increment() {
        ++value; // 增加线程局部变量的值
    }

    int get() const {
        return value; // 获取线程局部变量的值
    }

    void cancel() {
        canceled.store(true); // 设置取消标志
    }

    bool isCanceled() const {
        return canceled.load(); // 检查取消标志
    }
};

// 初始化静态成员变量
thread_local int ThreadLocalVariables::value = 0;

// 定义一个类，用于访问和操作线程局部变量
class Accessor {
    int id; // 线程标识符
    shared_ptr<ThreadLocalVariables> tlv; // 共享的线程局部变量管理对象

public:
    Accessor(shared_ptr<ThreadLocalVariables> tl, int idn) : id(idn), tlv(tl) {
        // 构造函数，初始化线程标识符和共享对象
    }

    void operator()() {
        while (!tlv->isCanceled()) {
            tlv->increment(); // 递增线程局部变量的值
            cout << *this << endl; // 输出当前线程的状态
            this_thread::sleep_for(chrono::milliseconds(10)); // 增加一些延迟，以便其他线程有机会运行
            this_thread::yield(); // 让出当前线程的执行权
        }
    }

    friend ostream& operator<<(ostream& os, const Accessor& a) {
        return os << "#" << a.id << ": " << a.tlv->get(); // 输出线程标识符和线程局部变量的值
    }
};

int main() {
    cout << "请按<Enter>键退出" << endl;

    try {
        auto tlv = make_shared<ThreadLocalVariables>(); // 创建一个共享的线程局部变量管理对象
        const int SZ = 5; // 定义线程数量
        vector<thread> threads; // 用于存储所有线程

        for (int i = 0; i < SZ; i++) {
            threads.emplace_back(Accessor(tlv, i)); // 创建并启动多个线程
        }

        cin.get(); // 等待用户按<Enter>键
        tlv->cancel(); // 设置取消标志，所有Accessor对象将退出

        for (auto& t : threads) {
            t.join(); // 等待所有线程结束
        }
    } catch (exception& e) {
        cerr << e.what() << endl; // 捕获并处理可能的异常
    }

    return 0; 
}