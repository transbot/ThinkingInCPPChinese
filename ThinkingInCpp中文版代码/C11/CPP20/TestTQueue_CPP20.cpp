//: C11:TestTQueue_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "TQueue_CPP20.h"
#include "LiftOff_CPP20.h"

using namespace std;

// LiftOffRunner��TQueue��ȡ��ÿ��LiftOff����ֱ������
class LiftOffRunner : public Runnable {
    TQueue<LiftOff*> rockets;
    atomic<bool> interrupted{false};

public:
    void add(LiftOff* lo) {
        rockets.put(lo);
    }

    void run() override {
        try {
            while (!interrupted.load()) {
                LiftOff* rocket = rockets.get();
                rocket->run();
            }
        } catch (const runtime_error&) {
            // �˳�
        }
        cout << "�˳�LiftOffRunner" << endl;
    }

    void interrupt() {
        interrupted.store(true);
    }
};

int main() {
    LiftOffRunner lor;

    // �����������̣߳�����LiftOffRunner��run����
    thread t(&LiftOffRunner::run, &lor);

    for (int i = 0; i < 5; i++)
        lor.add(new LiftOff(10, i));

    cin.get(); // ����<Enter>����Ӽ������һ��LiftOff����
    lor.add(new LiftOff(10, 99));
    cin.get(); // �ٰ���<Enter>�ж��̲߳��ȴ��߳̽���
    lor.interrupt();
    t.join();

    return 0;
}
