//: C11:ToastOMatic_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 用现代C++演示线程协作中的问题
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// 抹果酱器（Jammer）给涂好黄油的面包片抹果酱
class Jammer {
    mutex mtx;
    condition_variable cv;
    bool gotButteredToast = false;
    atomic<int> jammed{0};

public:
    void moreButteredToastReady() {
        lock_guard<mutex> lock(mtx);
        gotButteredToast = true;
        cv.notify_one();
    }

    void run() {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return gotButteredToast; });
            ++jammed;
            cout << "给面包 " << jammed << " 抹果酱" << endl;
            gotButteredToast = false;
        }
    }
};

// 涂黄油器（Butterer）给面包片涂黄油
class Butterer {
    mutex mtx;
    condition_variable cv;
    Jammer& jammer;
    bool gotToast = false;
    atomic<int> buttered{0};

public:
    Butterer(Jammer& j) : jammer(j) {}

    void moreToastReady() {
        lock_guard<mutex> lock(mtx);
        gotToast = true;
        cv.notify_one();
    }

    void run() {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return gotToast; });
            ++buttered;
            cout << "给面包 " << buttered << " 涂黄油" << endl;
            jammer.moreButteredToastReady();
            gotToast = false;
        }
    }
};

// 烤面包器Toaster烤面包
class Toaster {
    Butterer& butterer;
    atomic<int> toasted{0};

public:
    Toaster(Butterer& b) : butterer(b) {}

    void run() {
        while (true) {
            this_thread::sleep_for(chrono::milliseconds(rand() % 500));
            // 创建新的面包片
            cout << "新面包片 " << ++toasted << endl;
            butterer.moreToastReady();
        }
    }
};

int main() {
    srand(time(0)); // 初始化随机数生成器

    cout << "请按<Enter>键退出" << endl;

    Jammer jammer;
    Butterer butterer(jammer);
    Toaster toaster(butterer);

    thread t1(&Toaster::run, &toaster);
    thread t2(&Butterer::run, &butterer);
    thread t3(&Jammer::run, &jammer);

    cin.get();

    t1.detach(); // 让线程在后台运行并独立处理
    t2.detach();
    t3.detach();

    return 0;
}
