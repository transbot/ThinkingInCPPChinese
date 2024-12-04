//: C10:ObservedFlower.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示观察者模式
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Observable.h"
using namespace std;

class Flower {
    bool isOpen;
public:
    Flower() : isOpen(false),
        openNotifier(this), closeNotifier(this) {}
    void open() { // 打开花瓣
        isOpen = true;
        openNotifier.notifyObservers();
        closeNotifier.open();
    }
    void close() { // 关闭花瓣
        isOpen = false;
        closeNotifier.notifyObservers();
        openNotifier.close();
    }
    // 使用“内部类”惯用法：
    class OpenNotifier;
    friend class Flower::OpenNotifier;
    class OpenNotifier : public Observable {
        Flower* parent;
        bool alreadyOpen;
    public:
        OpenNotifier(Flower* f) : parent(f),
            alreadyOpen(false) {}
        void notifyObservers(Argument* arg = 0) {
            if(parent->isOpen && !alreadyOpen) {
                setChanged();
                Observable::notifyObservers();
                alreadyOpen = true;
            }
        }
        void close() { alreadyOpen = false; }
    } openNotifier;
    class CloseNotifier;
    friend class Flower::CloseNotifier;
    class CloseNotifier : public Observable {
        Flower* parent;
        bool alreadyClosed;
    public:
        CloseNotifier(Flower* f) : parent(f),
            alreadyClosed(false) {}
        void notifyObservers(Argument* arg = 0) {
            if(!parent->isOpen && !alreadyClosed) {
                setChanged();
                Observable::notifyObservers();
                alreadyClosed = true;
            }
        }
        void open() { alreadyClosed = false; }
    } closeNotifier;
};

class Bee {
    string name;
    // 用于观察开放的“内部类”：
    class OpenObserver;
    friend class Bee::OpenObserver;
    class OpenObserver : public Observer {
        Bee* parent;
    public:
        OpenObserver(Bee* b) : parent(b) {}
        void update(Observable*, Argument *) {
            cout << "蜜蜂 " << parent->name
                << " 的早餐时间到了！" << endl;
        }
    } openObsrv;
    // 用于观察关闭的另一个“内部类”：
    class CloseObserver;
    friend class Bee::CloseObserver;
    class CloseObserver : public Observer {
        Bee* parent;
    public:
        CloseObserver(Bee* b) : parent(b) {}
        void update(Observable*, Argument *) {
            cout << "蜜蜂 " << parent->name
                << " 的上床睡觉时间到了！" << endl;
        }
    } closeObsrv;
public:
    Bee(string nm) : name(nm),
        openObsrv(this), closeObsrv(this) {}
    Observer& openObserver() { return openObsrv; }
    Observer& closeObserver() { return closeObsrv;}
};

class Hummingbird {
    string name;
    class OpenObserver;
    friend class Hummingbird::OpenObserver;
    class OpenObserver : public Observer {
        Hummingbird* parent;
    public:
        OpenObserver(Hummingbird* h) : parent(h) {}
        void update(Observable*, Argument *) {
            cout << "蜂鸟 " << parent->name
                << " 的早餐时间到了！" << endl;
        }
    } openObsrv;
    class CloseObserver;
    friend class Hummingbird::CloseObserver;
    class CloseObserver : public Observer {
        Hummingbird* parent;
    public:
        CloseObserver(Hummingbird* h) : parent(h) {}
        void update(Observable*, Argument *) {
            cout << "蜂鸟 " << parent->name
                << " 的上床睡觉时间到了！" << endl;
        }
    } closeObsrv;
public:
    Hummingbird(string nm) : name(nm),
        openObsrv(this), closeObsrv(this) {}
    Observer& openObserver() { return openObsrv; }
    Observer& closeObserver() { return closeObsrv;}
};

int main() {
    Flower f;
    Bee ba("A"), bb("B");
    Hummingbird ha("A"), hb("B");
    f.openNotifier.addObserver(ha.openObserver());
    f.openNotifier.addObserver(hb.openObserver());
    f.openNotifier.addObserver(ba.openObserver());
    f.openNotifier.addObserver(bb.openObserver());
    f.closeNotifier.addObserver(ha.closeObserver());
    f.closeNotifier.addObserver(hb.closeObserver());
    f.closeNotifier.addObserver(ba.closeObserver());
    f.closeNotifier.addObserver(bb.closeObserver());
    // 蜂鸟B决定赖床：
    f.openNotifier.deleteObserver(hb.openObserver());
    // 发生了一些观察者感兴趣的事件：
    f.open();
    f.open(); // 已经开花了，没有变化。
    // 蜜蜂A不想上床睡觉：
    f.closeNotifier.deleteObserver(
        ba.closeObserver());
    f.close();
    f.close(); // 已经关上了；没有变化
    f.openNotifier.deleteObservers();
    f.open();
    f.close();
} ///:~