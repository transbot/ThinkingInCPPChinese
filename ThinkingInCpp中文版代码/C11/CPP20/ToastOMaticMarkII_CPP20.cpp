//: C11:ToastOMaticMarkII_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��TQueue�������
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
            case DRY: return "�����Ƭ";
            case BUTTERED: return "Ϳ�˻���";
            case JAMMED: return "Ĩ�˹���";
            default: return "����";
        }
    }
    int getId() const { return id; }
    friend ostream& operator<<(ostream& os, const Toast& t) {
        return os << "��� " << t.id << ": " << t.getStatus();
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
            // �˳�
        }
        cout << "���������Toaster���ر�" << endl;
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
            // �˳�
        }
        cout << "Ϳ��������Butterer���ر�" << endl;
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
            // �˳�
        }
        cout << "Ĩ��������Jammer���ر�" << endl;
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
                if (t.getId() != counter++ || t.getStatus() != "Ĩ�˹���") {
                    cout << ">>>> ����: " << t << endl;
                    exit(1);
                } else {
                    cout << "�Ե����� " << t << endl;
                }
            }
        } catch (...) {
            // �˳�
        }
        cout << "ʳ�ͣ�Eater���ر�" << endl;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // ��ʼ�������������

    ToastQueue dryQueue = make_shared< TQueue<Toast> >();
    ToastQueue butteredQueue = make_shared< TQueue<Toast> >();
    ToastQueue finishedQueue = make_shared< TQueue<Toast> >();

    cout << "�밴<Enter>���˳�" << endl;

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
