//: C11:DeadlockingDiningPhilosophers_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �����������ܵľͲ���ѧ������
#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "DiningPhilosophers_CPP20.h"
using namespace std;

int main(int argc, char* argv[]) {
    // ��ʼ�������������
    srand(static_cast<unsigned>(time(0)));

    // ��ȡ�����в�����������ѧ��˼����ʱ������
    int ponder = (argc > 1) ? atoi(argv[1]) : 5;
    cout << "�밴<ENTER>���˳�" << endl;

    // ���峣������ʾ��ѧ�ҵ�����
    const int NUM_PHILOSOPHERS = 5;

    try {        
        // ������ʾ����
        auto display = make_shared<Display>();

        // ������������
        vector<Chopstick> chopsticks(NUM_PHILOSOPHERS);

        // ������ѧ�����飬���������ǵ��߳�
        vector<shared_ptr<Philosopher>> philosophers;
        for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
            // ������ѧ�Ҷ���
            auto philosopher = make_shared<Philosopher>(
                chopsticks[i], chopsticks[(i + 1) % NUM_PHILOSOPHERS],
                display, i, ponder
            );

            // ������ѧ���߳�
            philosopher->start();

            // ����ѧ����ӵ�������
            philosophers.push_back(philosopher);
        }

        // �ȴ��û�����Enter��
        cin.get();

        // ����������ѧ���߳�ֹͣ
        for (auto& philosopher : philosophers) {
            philosopher->request_stop();
        }

        // ���̵߳ȴ�һ��ʱ�䣬ȷ��������ѧ���߳����㹻��ʱ���˳�
        this_thread::sleep_for(chrono::seconds(1));

        // ���������Ϣ
        cout << "������ѧ�����˳�" << endl;

    } catch (const exception& e) {
        cerr << "�쳣: " << e.what() << endl;
    }

    return 0;
}
