//: C11:BasicThreads_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#include <iostream>
#include <thread> // ʹ���ִ�C++���߳̿�
using namespace std;

class LiftOff {
    int count;
public:
    LiftOff(int countdown) : count(countdown) {}
    void operator()() {
        while (count > 0) {
            cout << count-- << "�����" << endl;
            this_thread::sleep_for(chrono::seconds(1)); // ģ�⵹��ʱ
        }
        cout << "���!" << endl;
    }
};

int main() {
    try {
        // �����̲߳�����LiftOff����
        thread t(LiftOff(10)); 
        cout << "��𵹼�ʱ" << endl;

        // �ȴ��߳̽���
        t.join();
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return 0; ///:~
}
