//: C11:Incrementer.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���߳���������ʱ���ٶ���ᵼ����������
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/ThreadedExecutor.h"

using namespace ZThread;
using namespace std;

class Count {
    enum { SZ = 100 };
    int n[SZ];
public:
    void increment() {
        for(int i = 0; i < SZ; i++)
            n[i]++;
    }
};

class Incrementer : public Runnable {
    Count* count;
public:
    Incrementer(Count* c) : count(c) {}
    void run() {
        for(int n = 100; n > 0; n--) {
            Thread::sleep(250);
            count->increment();
        }
    }
};

int main() {
    cout << "�⽫���¶δ���" << endl;
    Count count;
    try {
        // �����̹߳���ͬһ��count����
        Thread t0(new Incrementer(&count));
        Thread t1(new Incrementer(&count));
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
