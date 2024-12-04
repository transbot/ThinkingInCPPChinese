//: C11:Interrupting2_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �жϱ�ͬ�������������߳�
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

// ģ�ⱻ�����Ļ�����
class BlockedMutex {
    mutex mtx;
    atomic<bool> acquired;

public:
    BlockedMutex() : acquired(false) {
        mtx.lock();
        acquired = true;
    }

    void f() {
        // ��ͼ��ȡ�����������������Ѿ�����ȡ����˻�һֱ����
        lock_guard<mutex> g(mtx);
    }

    bool isAcquired() const {
        return acquired;
    }

    void release() {
        if (acquired) {
            mtx.unlock();
            acquired = false;
        }
    }
};

// ģ���������������߳�
class Blocked2 {
    BlockedMutex blocked;

public:
    void run() {
        try {
            cout << "�ȴ�BlockedMutex�е�f()" << endl;
            blocked.f();
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
            // �˳�����
        }
    }

    void interrupt() {
        blocked.release();
    }
};

int main(int argc, char* argv[]) {
    Blocked2 blocked2;

    // �����������̣߳�����Blocked2::run����
    thread t(&Blocked2::run, &blocked2);

    // ģ��һЩ����
    if (argc > 1) {
        this_thread::sleep_for(chrono::milliseconds(1100));
    }

    // �ж��߳�
    blocked2.interrupt();

    // �ȴ��߳̽���
    t.join();

    return 0;
}
