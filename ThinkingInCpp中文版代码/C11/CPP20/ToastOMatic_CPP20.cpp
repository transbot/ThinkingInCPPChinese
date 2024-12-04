//: C11:ToastOMatic_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���ִ�C++��ʾ�߳�Э���е�����
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Ĩ��������Jammer����Ϳ�û��͵����ƬĨ����
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
            cout << "����� " << jammed << " Ĩ����" << endl;
            gotButteredToast = false;
        }
    }
};

// Ϳ��������Butterer�������ƬͿ����
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
            cout << "����� " << buttered << " Ϳ����" << endl;
            jammer.moreButteredToastReady();
            gotToast = false;
        }
    }
};

// �������Toaster�����
class Toaster {
    Butterer& butterer;
    atomic<int> toasted{0};

public:
    Toaster(Butterer& b) : butterer(b) {}

    void run() {
        while (true) {
            this_thread::sleep_for(chrono::milliseconds(rand() % 500));
            // �����µ����Ƭ
            cout << "�����Ƭ " << ++toasted << endl;
            butterer.moreToastReady();
        }
    }
};

int main() {
    srand(time(0)); // ��ʼ�������������

    cout << "�밴<Enter>���˳�" << endl;

    Jammer jammer;
    Butterer butterer(jammer);
    Toaster toaster(butterer);

    thread t1(&Toaster::run, &toaster);
    thread t2(&Butterer::run, &butterer);
    thread t3(&Jammer::run, &jammer);

    cin.get();

    t1.detach(); // ���߳��ں�̨���в���������
    t2.detach();
    t3.detach();

    return 0;
}
