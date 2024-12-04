// C11:MoreBasicThreads_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��Ӹ����߳�
#include <iostream>
#include <thread>
#include <vector>
#include "LiftOff_CPP20.h"

using namespace std;

int main() {
    const int SZ = 5;
    try {
        vector<thread> threads; // ���ڴ洢�̶߳��������
        vector<LiftOff*> liftOffs; // ���ڴ洢LiftOff���������

        for(int i = 0; i < SZ; i++) {
            // ����һ��LiftOff���󣬵���ʱ10�Σ������ʶ��Ϊi
            LiftOff* liftoff = new LiftOff(10, i);
            // ����һ���̣߳�ִ��LiftOff�����run����
            threads.emplace_back(&LiftOff::run, liftoff);
            // �洢LiftOff����ָ��
            liftOffs.push_back(liftoff);
        }
        cout << "��𵹼�ʱ" << endl; // ��ӡ�ȴ���Ϣ
        // �ȴ������߳̽���
        for(auto& t : threads) {
            t.join();
        }
        // ����̬�����LiftOff����
        for(LiftOff* liftoff : liftOffs) {
            delete liftoff;
        }
    } catch (const std::exception& e) {
        // ���񲢴�ӡ�쳣
        cerr << "�쳣: " << e.what() << endl;
    }
    return 0;
}