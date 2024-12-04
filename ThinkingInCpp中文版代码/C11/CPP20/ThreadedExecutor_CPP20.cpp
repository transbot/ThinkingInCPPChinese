// C11:ThreadedExecutor_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ���ִ�C++��׼��ʵ������ZThread::ThreadedExecutor�Ĺ���
#include <iostream>
#include <thread>
#include <vector>
#include "LiftOff_CPP20.h"

using namespace std;

class SimpleExecutor {
private:
    vector<thread> threads;

public:
    void execute(Runnable* task) {
        threads.emplace_back([task] {
            task->run();
            delete task; // �ͷ��������
        });
    }

    ~SimpleExecutor() {
        for (auto& t : threads) {
            if (t.joinable()) {
                t.join();
            }
        }
    }
};

int main() {
    try {
        SimpleExecutor executor;
        for(int i = 0; i < 5; i++) {
            executor.execute(new LiftOff(10, i));
        }
    } catch(const exception& e) {
        cerr << "�쳣: " << e.what() << endl;
    }
    cout << "�������������" << endl;
    return 0;
}