// C11:FixedDiningPhilosophers_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �����������ܵľͲ���ѧ������
// ��ԭ����������޸ģ���������Դ��λ�������ֹ������
// �����˵������ȷ����ѧ�����ǰ�����ͬ��˳��������ӡ�
// ���磬ÿ����ѧ�����ñ��С�Ŀ��ӣ����ñ�Ŵ�Ŀ��ӡ�
// ͨ�����ַ��������Ա���ѭ���ȴ����Ӷ�����������

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
        // ����Display����
        auto display = make_shared<Display>();

        // ������������
        vector<Chopstick> chopsticks(NUM_PHILOSOPHERS);

        // ������ѧ�����飬���������ǵ��߳�
        /* Ϊ�˱�����������ѧ���ǽ�����ͳһ��˳���ÿ��ӡ������˵�������������ñ�Ž�С�Ŀ��ӣ����ñ�Žϴ�Ŀ��ӡ�����ζ�ţ�
             ���Ϊ 0 ����ѧ�ҽ����� chopsticks[0] ���� chopsticks[1]��
             ���Ϊ 1 ����ѧ�ҽ����� chopsticks[1] ���� chopsticks[2]��
             ���Ϊ 2 ����ѧ�ҽ����� chopsticks[2] ���� chopsticks[3]��
             ���Ϊ 3 ����ѧ�ҽ����� chopsticks[3] ���� chopsticks[4]��
             ���Ϊ 4 ����ѧ�ҽ����� chopsticks[0] ���� chopsticks[4]����Ϊ 4 % 5 = 0����
           ͨ�����ַ�ʽ��ÿ����ѧ���������ñ�Ž�С�Ŀ��ӣ������Ϳ��Ա����γ�ѭ���ȴ���������Ӷ���ֹ������ */
           
        vector<shared_ptr<Philosopher>> philosophers;
        for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
            // ������ѧ�����ñ��С�Ŀ��ӣ����ñ�Ŵ�Ŀ���
            auto philosopher = make_shared<Philosopher>(
                chopsticks[min(i, (i + 1) % NUM_PHILOSOPHERS)],
                chopsticks[max(i, (i + 1) % NUM_PHILOSOPHERS)],
                display, i, ponder
            );
            philosopher->start();
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
