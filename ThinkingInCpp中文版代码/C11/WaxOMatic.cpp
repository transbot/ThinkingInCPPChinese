//: C11:WaxOMatic.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �������߳�Э��
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
    Mutex lock; // ������
    Condition condition; // �ִ�C++Ӧʹ����������
    bool waxOn; // ��ʾ�Ƿ��Ѿ��������׼���׹�
public:
    Car() : condition(lock), waxOn(false) {}
    void waxed() {
        Guard<Mutex> g(lock);
        waxOn = true; // ������ɣ�׼�����׹�
        condition.signal();
    }
    void buffed() {
        Guard<Mutex> g(lock);
        waxOn = false; // �׹���ɣ���׼������Ϳһ����
        condition.signal();
    }
    void waitForWaxing() { // �ȴ������������
        Guard<Mutex> g(lock);
        while(waxOn == false)
            condition.wait();
    }
    void waitForBuffing() { // �ȴ������׹����
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
                cout << "���ڴ���!" << endl;
                Thread::sleep(200);
                car->waxed();
                car->waitForBuffing();
            }
        } catch(Interrupted_Exception&) {
            // �˳�
        }
        cout << "������������" << endl;
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
                cout << "�����׹�!" << endl;
                Thread::sleep(200);
                car->buffed();
            }
        } catch(Interrupted_Exception&) {
            // �˳�
        }
        cout << "�����׹����" << endl;
    }
};

int main() {
    cout << "�밴<Enter>���˳�" << endl;
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
