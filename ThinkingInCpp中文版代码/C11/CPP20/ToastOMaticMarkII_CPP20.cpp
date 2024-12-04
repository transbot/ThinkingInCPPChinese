//: C11:ToastOMaticMarkII_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用TQueue解决问题
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "TQueue_CPP20.h"

using namespace std;

class Toast {
    enum Status { DRY, BUTTERED, JAMMED };
    Status status;
    int id;
public:
    Toast(int idn) : status(DRY), id(idn) {}
    void butter() { status = BUTTERED; }
    void jam() { status = JAMMED; }
    string getStatus() const {
        switch(status) {
            case DRY: return "干面包片";
            case BUTTERED: return "涂了黄油";
            case JAMMED: return "抹了果酱";
            default: return "错误";
        }
    }
    int getId() const { return id; }
    friend ostream& operator<<(ostream& os, const Toast& t) {
        return os << "面包 " << t.id << ": " << t.getStatus();
    }
};

typedef shared_ptr< TQueue<Toast> > ToastQueue;

class Toaster {
    ToastQueue toastQueue;
    int count;
public:
    Toaster(ToastQueue tq) : toastQueue(tq), count(0) {}
    void run() {
        try {
            while (true) {
                this_thread::sleep_for(chrono::milliseconds(rand() % 500));
                Toast t(count++);
                cout << t << endl;
                toastQueue->put(t);
            }
        } catch (...) {
            // 退出
        }
        cout << "烤面包机（Toaster）关闭" << endl;
    }
};

class Butterer {
    ToastQueue dryQueue, butteredQueue;
public:
    Butterer(ToastQueue dry, ToastQueue buttered)
    : dryQueue(dry), butteredQueue(buttered) {}
    void run() {
        try {
            while (true) {
                Toast t = dryQueue->get();
                t.butter();
                cout << t << endl;
                butteredQueue->put(t);
            }
        } catch (...) {
            // 退出
        }
        cout << "涂黄油器（Butterer）关闭" << endl;
    }
};

class Jammer {
    ToastQueue butteredQueue, finishedQueue;
public:
    Jammer(ToastQueue buttered, ToastQueue finished)
    : butteredQueue(buttered), finishedQueue(finished) {}
    void run() {
        try {
            while (true) {
                Toast t = butteredQueue->get();
                t.jam();
                cout << t << endl;
                finishedQueue->put(t);
            }
        } catch (...) {
            // 退出
        }
        cout << "抹果酱器（Jammer）关闭" << endl;
    }
};

class Eater {
    ToastQueue finishedQueue;
    int counter;
public:
    Eater(ToastQueue finished)
    : finishedQueue(finished), counter(0) {}
    void run() {
        try {
            while (true) {
                Toast t = finishedQueue->get();
                if (t.getId() != counter++ || t.getStatus() != "抹了果酱") {
                    cout << ">>>> 错误: " << t << endl;
                    exit(1);
                } else {
                    cout << "吃掉它！ " << t << endl;
                }
            }
        } catch (...) {
            // 退出
        }
        cout << "食客（Eater）关闭" << endl;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // 初始化随机数生成器

    ToastQueue dryQueue = make_shared< TQueue<Toast> >();
    ToastQueue butteredQueue = make_shared< TQueue<Toast> >();
    ToastQueue finishedQueue = make_shared< TQueue<Toast> >();

    cout << "请按<Enter>键退出" << endl;

    Toaster toaster(dryQueue);
    Butterer butterer(dryQueue, butteredQueue);
    Jammer jammer(butteredQueue, finishedQueue);
    Eater eater(finishedQueue);

    thread t1(&Toaster::run, &toaster);
    thread t2(&Butterer::run, &butterer);
    thread t3(&Jammer::run, &jammer);
    thread t4(&Eater::run, &eater);

    cin.get();

    t1.detach();
    t2.detach();
    t3.detach();
    t4.detach();

    return 0;
}
