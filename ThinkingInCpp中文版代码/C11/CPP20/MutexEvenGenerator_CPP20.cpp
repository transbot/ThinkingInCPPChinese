//: C11:MutexEvenGenerator_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用互斥锁防止线程冲突
#include <iostream>
#include <thread>
#include <mutex> // 引入标准库中的互斥锁
#include "EvenChecker_CPP20.h"

class MutexEvenGenerator : public Generator {
    unsigned int currentEvenValue;
    std::mutex lock; // 使用std::mutex替代ZThread::Mutex
public:
    MutexEvenGenerator() : currentEvenValue(0) {}
    ~MutexEvenGenerator() {
        std::cout << "~MutexEvenGenerator" << std::endl;
    }
    int nextValue() {
        lock.lock(); // 手动获取锁
        ++currentEvenValue;
        std::this_thread::yield(); // 标准库中的yield，用于加快失败速度（如果会失败的话）
        ++currentEvenValue;
        int rval = currentEvenValue;
        lock.unlock(); // 手动释放锁
        return rval;
    }
};

int main() {
    EvenChecker::test<MutexEvenGenerator>();
} ///:~
