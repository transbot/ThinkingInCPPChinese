//: C11:ThreadLocalVariables.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �Զ�Ϊÿ���̷߳����Լ��Ĵ洢
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
    cout << "�밴<Enter>���˳�" << endl;
    try {
        CountedPtr<ThreadLocalVariables> tlv(new ThreadLocalVariables);
        const int SZ = 5;
        ThreadedExecutor executor;
        for (int i = 0; i < SZ; i++) {
            executor.execute(new Accessor(tlv, i));
        }
        cin.get();
        tlv->cancel(); // ����Accessor�����˳�
    } catch (Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
