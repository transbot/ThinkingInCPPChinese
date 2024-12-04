/* ��Runnable������һ���ಢ��дrun()��������run()�ڴ�ӡһ����Ϣ��Ȼ�����sleep()��
�ظ������������Σ�Ȼ���run()���ء��ڹ��캯������ʾһ��������Ϣ����������ֹʱ��ʾһ���ر���Ϣ��
���������͵ļ����̶߳������������Բ鿴�ᷢ��ʲô��
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "Runnable_CPP20.h"

using namespace std;

// ��Runnable������һ����Task
class Task : public Runnable {
    int id; // ����ID

public:
    // ���캯������ӡ������Ϣ
    Task(int id) : id(id) {
        cout << "���� " << id << " ����" << endl;
    }

    // ��дrun()����
    void run() override {
        for (int i = 0; i < 3; ++i) {
            cout << "���� " << id << " ����ִ�е� " << (i + 1) << " ��" << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }

    // ������������ӡ�ر���Ϣ
    ~Task() override {
        cout << "���� " << id << " �ر�" << endl;
    }
};

// �����������������ж������
int main() {
    // ������� Task ������������
    Task t1(1), t2(2), t3(3);
    thread th1(&Task::run, &t1);
    thread th2(&Task::run, &t2);
    thread th3(&Task::run, &t3);

    // �ȴ������߳����
    th1.join();
    th2.join();
    th3.join();

    return 0;
}
