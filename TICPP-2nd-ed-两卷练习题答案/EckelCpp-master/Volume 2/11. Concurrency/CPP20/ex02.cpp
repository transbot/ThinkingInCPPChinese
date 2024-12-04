#include <iostream>
#include <thread>
#include <vector>
#include "LiftOff_CPP20.h"

// ������޸ĺ�ĳ����У�
// �������ȴ�����һ����ʼ��LiftOff���󣬲���һ���߳�ִ������run������
// Ȼ�����Ǵ�����һ��extraThreads���������ڴ洢�����LiftOff �̡߳�ÿ�����߳�ִ��һ���µ�LiftOff�����run������������Щ�߳���ӵ������С�
// ���̵߳ȴ���ʼ��LiftOff�߳���ɺ󣬵ȴ����ж����LiftOff�߳���ɡ�
using namespace std;

int main() {
    try {
        // ����һ��LiftOff���󣬵���ʱ10�Σ������ʶ��Ĭ��Ϊ0
        LiftOff liftoff(10);
        // ����һ���̣߳�ִ��LiftOff�����run����
        std::thread t(&LiftOff::run, &liftoff);
        cout << "��𵹼�ʱ" << endl; // ��ӡ�ȴ���Ϣ

        // ���������������LiftOff�߳�
        vector<std::thread> extraThreads;
        for (int i = 1; i <= 3; ++i) {
            extraThreads.emplace_back(&LiftOff::run, new LiftOff(10, i));
        }

        // �ȴ���ʼ�߳̽���
        t.join();

        // �ȴ����ж����LiftOff�߳̽���
        for (auto& t : extraThreads) {
            if (t.joinable()) {
                t.join();
            }
        }

    } catch (const std::exception& e) {
        // ���񲢴�ӡ�쳣
        cerr << "�쳣: " << e.what() << endl;
    }
    return 0;
}
