//: C11:BasicThreads_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// Thread���������Ӧ��
#include <iostream>
#include <thread>
#include "LiftOff_CPP20.h"

using namespace std;

int main() {
    try {
        // ����һ��LiftOff���󣬵���ʱ10�Σ������ʶ��Ĭ��Ϊ0
        LiftOff liftoff(10);
        // ����һ���̣߳�ִ��LiftOff�����run����
        std::thread t(&LiftOff::run, &liftoff);
        cout << "��𵹼�ʱ" << endl; // ��ӡ�ȴ���Ϣ
        // �ȴ��߳̽���
        t.join();
    } catch (const std::exception& e) {
        // ���񲢴�ӡ�쳣
        cerr << "�쳣: " << e.what() << endl;
    }
    return 0;
} ///:~