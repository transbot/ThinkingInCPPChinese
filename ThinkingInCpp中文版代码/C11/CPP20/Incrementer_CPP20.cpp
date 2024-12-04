//: C11:Incrementer_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 用现代C++技术来演示因为两个线程共享同一个在程序结束时销毁的对象而发生的“段错误”。
// n最终的累加结果应该是200万，多运行几次，就会发现蹊跷。
/* 共享对象: Count对象被两个线程共享，它们都指向同一个内存地址。
   并发访问: 两个线程同时对count.n进行修改，没有同步机制。
   段错误原因:
       1. 当main函数结束时，count对象的生命周期也结束，其占用的内存被释放。
       2. 但是，t1和t2线程可能还没有完成对count.n的修改操作。
       3. 当这些线程试图访问已经被释放的内存时，就会触发段错误。
*/
#include <thread>
#include <vector>
#include <iostream>

class Count {
public:
    int n = 0;
    void increment() {
        n++;
    }
};

void incrementer(Count* count) {
    for (int i = 0; i < 1000000; ++i) {
        count->increment();
    }
}

int main() {
    Count count;
    std::thread t1(incrementer, &count);
    std::thread t2(incrementer, &count);

    t1.join();
    t2.join();

    std::cout << count.n << std::endl;
    return 0;
}