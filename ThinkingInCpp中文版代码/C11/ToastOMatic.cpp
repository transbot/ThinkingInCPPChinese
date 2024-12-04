//: C11:ToastOMatic.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示线程协作中的问题
//{L} ZThread
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include "zthread/Condition.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

// 抹果酱器（Jammer）给涂好黄油的面包片抹果酱
class Jammer : public Runnable {
    Mutex lock;
    Condition butteredToastReady;
    bool gotButteredToast;
    int jammed;
public:
    Jammer() : butteredToastReady(lock) {
        gotButteredToast = false;
        jammed = 0;
    }
    void moreButteredToastReady() {
        Guard<Mutex> g(lock);
        gotButteredToast = true;
        butteredToastReady.signal();
    }
    void run() {
        try {
            while(!Thread::interrupted()) {
                {
                    Guard<Mutex> g(lock);
                    while(!gotButteredToast)
                        butteredToastReady.wait();
                    ++jammed;
                }
                cout << "给面包 " << jammed << " 抹果酱" << endl;
                {
                    Guard<Mutex> g(lock);
                    gotButteredToast = false;
                }
            }
        } catch(Interrupted_Exception&) {
            // 退出
        }
        cout << "抹果酱器（Jammer）关闭" << endl;
    }
};

// 涂黄油器（Butterer）给面包片涂黄油
class Butterer : public Runnable {
    Mutex lock;
    Condition toastReady;
    CountedPtr<Jammer> jammer;
    bool gotToast;
    int buttered;
public:
    Butterer(CountedPtr<Jammer>& j) : toastReady(lock), jammer(j) {
        gotToast = false;
        buttered = 0;
    }
    void moreToastReady() {
        Guard<Mutex> g(lock);
        gotToast = true;
        toastReady.signal();
    }
    void run() {
        try {
            while(!Thread::interrupted()) {
                {
                    Guard<Mutex> g(lock);
                    while(!gotToast)
                        toastReady.wait();
                    ++buttered;
                }
                cout << "给面包 " << buttered << " 涂黄油" << endl;
                jammer->moreButteredToastReady();
                {
                    Guard<Mutex> g(lock);
                    gotToast = false;
                }
            }
        } catch(Interrupted_Exception&) {
            // 退出
        }
        cout << "涂黄油器（Butterer）关闭" << endl;
    }
};

// 烤面包器Toaster烤面包
class Toaster : public Runnable {
    CountedPtr<Butterer> butterer;
    int toasted;
public:
    Toaster(CountedPtr<Butterer>& b) : butterer(b) {
        toasted = 0;
    }
    void run() {
        try {
            while(!Thread::interrupted()) {
                Thread::sleep(rand()/(RAND_MAX/5)*100);
                // ...
                // 创建新的面包片
                // ...
                cout << "新面包片 " << ++toasted << endl;
                butterer->moreToastReady();
            }
        } catch(Interrupted_Exception&) {
            // 退出
        }
        cout << "烤面包器关闭" << endl;
    }
};

int main() {
    srand(time(0)); // 初始化随机数生成器
    try {
        cout << "请按<Enter>键退出" << endl;
        CountedPtr<Jammer> jammer(new Jammer);
        CountedPtr<Butterer> butterer(new Butterer(jammer));
        ThreadedExecutor executor;
        executor.execute(new Toaster(butterer));
        executor.execute(butterer);
        executor.execute(jammer);
        cin.get();
        executor.interrupt();
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
