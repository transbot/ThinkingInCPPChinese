//: C11:ToastOMatic.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ�߳�Э���е�����
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

// Ĩ��������Jammer����Ϳ�û��͵����ƬĨ����
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
                cout << "����� " << jammed << " Ĩ����" << endl;
                {
                    Guard<Mutex> g(lock);
                    gotButteredToast = false;
                }
            }
        } catch(Interrupted_Exception&) {
            // �˳�
        }
        cout << "Ĩ��������Jammer���ر�" << endl;
    }
};

// Ϳ��������Butterer�������ƬͿ����
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
                cout << "����� " << buttered << " Ϳ����" << endl;
                jammer->moreButteredToastReady();
                {
                    Guard<Mutex> g(lock);
                    gotToast = false;
                }
            }
        } catch(Interrupted_Exception&) {
            // �˳�
        }
        cout << "Ϳ��������Butterer���ر�" << endl;
    }
};

// �������Toaster�����
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
                // �����µ����Ƭ
                // ...
                cout << "�����Ƭ " << ++toasted << endl;
                butterer->moreToastReady();
            }
        } catch(Interrupted_Exception&) {
            // �˳�
        }
        cout << "��������ر�" << endl;
    }
};

int main() {
    srand(time(0)); // ��ʼ�������������
    try {
        cout << "�밴<Enter>���˳�" << endl;
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
