//: C11:ThreadLocalVariables.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 自动为每个线程分配自己的存储
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/Cancelable.h"
#include "zthread/ThreadLocal.h"
#include "zthread/CountedPtr.h"

using namespace ZThread;
using namespace std;

class ThreadLocalVariables : public Cancelable {
    ThreadLocal<int> value;
    bool canceled;
    Mutex lock;

public:
    ThreadLocalVariables() : canceled(false) {
        value.set(0);
    }
    void increment() {
        value.set(value.get() + 1);
    }
    int get() {
        return value.get();
    }
    void cancel() {
        Guard<Mutex> g(lock);
        canceled = true;
    }
    bool isCanceled() {
        Guard<Mutex> g(lock);
        return canceled;
    }
};

class Accessor : public Runnable {
    int id;
    CountedPtr<ThreadLocalVariables> tlv;

public:
    Accessor(CountedPtr<ThreadLocalVariables>& tl, int idn) : id(idn), tlv(tl) {}

    void run() {
        while (!tlv->isCanceled()) {
            tlv->increment();
            cout << *this << endl;
        }
    }

    friend ostream& operator<<(ostream& os, Accessor& a) {
        return os << "#" << a.id << ": " << a.tlv->get();
    }
};

int main() {
    cout << "请按<Enter>键退出" << endl;
    try {
        CountedPtr<ThreadLocalVariables> tlv(new ThreadLocalVariables);
        const int SZ = 5;
        ThreadedExecutor executor;
        for (int i = 0; i < SZ; i++) {
            executor.execute(new Accessor(tlv, i));
        }
        cin.get();
        tlv->cancel(); // 所有Accessor都将退出
    } catch (Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
