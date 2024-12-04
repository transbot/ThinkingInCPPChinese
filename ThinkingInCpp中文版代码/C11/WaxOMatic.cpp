//: C11:WaxOMatic.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 基本的线程协作
//{L} ZThread
#include <iostream>
#include <string>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include "zthread/Condition.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

class Car {
    Mutex lock; // 互锁锁
    Condition condition; // 现代C++应使用条件变量
    bool waxOn; // 表示是否已经打好腊，准备抛光
public:
    Car() : condition(lock), waxOn(false) {}
    void waxed() {
        Guard<Mutex> g(lock);
        waxOn = true; // 打腊完成，准备好抛光
        condition.signal();
    }
    void buffed() {
        Guard<Mutex> g(lock);
        waxOn = false; // 抛光完成，已准备好再涂一层蜡
        condition.signal();
    }
    void waitForWaxing() { // 等待汽车打蜡完成
        Guard<Mutex> g(lock);
        while(waxOn == false)
            condition.wait();
    }
    void waitForBuffing() { // 等待汽车抛光完成
        Guard<Mutex> g(lock);
        while(waxOn == true)
            condition.wait();
    }
};

class WaxOn : public Runnable {
    CountedPtr<Car> car;
public:
    WaxOn(CountedPtr<Car>& c) : car(c) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                cout << "正在打蜡!" << endl;
                Thread::sleep(200);
                car->waxed();
                car->waitForBuffing();
            }
        } catch(Interrupted_Exception&) {
            // 退出
        }
        cout << "结束打蜡过程" << endl;
    }
};

class WaxOff : public Runnable {
    CountedPtr<Car> car;
public:
    WaxOff(CountedPtr<Car>& c) : car(c) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                car->waitForWaxing();
                cout << "正在抛光!" << endl;
                Thread::sleep(200);
                car->buffed();
            }
        } catch(Interrupted_Exception&) {
            // 退出
        }
        cout << "结束抛光过程" << endl;
    }
};

int main() {
    cout << "请按<Enter>键退出" << endl;
    try {
        CountedPtr<Car> car(new Car);
        ThreadedExecutor executor;
        executor.execute(new WaxOff(car));
        executor.execute(new WaxOn(car));
        cin.get();
        executor.interrupt();
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
}///:~
