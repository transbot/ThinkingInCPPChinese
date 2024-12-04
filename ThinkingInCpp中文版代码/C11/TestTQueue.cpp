//: C11:TestTQueue.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
//{L} ZThread
#include <string>
#include <iostream>
#include "TQueue.h"
#include "zthread/Thread.h"
#include "LiftOff.h"
using namespace ZThread;
using namespace std;

class LiftOffRunner : public Runnable {
    TQueue<LiftOff*> rockets;
public:
    void add(LiftOff* lo) {
        rockets.put(lo);
    }
    void run() {
        try {
            while(!Thread::interrupted()) {
                LiftOff* rocket = rockets.get();
                rocket->run();
            }
        } catch(Interrupted_Exception&) {
            // �˳�
        }
        cout << "�˳�LiftOffRunner" << endl;
    }
};

int main() {
    try {
        LiftOffRunner* lor = new LiftOffRunner;
        Thread t(lor);

        for(int i = 0; i < 5; i++)
            lor->add(new LiftOff(10, i));

        cin.get();

        lor->add(new LiftOff(10, 99));

        cin.get();

        t.interrupt();
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
