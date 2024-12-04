// C11:SleepingTask_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����sleep_for()����ͣһ��ʱ��
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

class SleepingTask {
    int countDown;
    int id;

public:
    SleepingTask(int ident = 0) : countDown(5), id(ident) {}
    ~SleepingTask() {
        cout << id << " ���" << endl;
    }
    friend ostream& operator<<(ostream& os, const SleepingTask& st) {
        return os << "#" << st.id << ": " << st.countDown;
    }
    void run() {
        while(true) {
            try {
                cout << *this << endl;
                if(--countDown == 0) return;
                this_thread::sleep_for(chrono::milliseconds(100)); // ��ͣ100����
            } catch(exception& e) {
                cerr << id << "�̷߳����쳣: " << e.what() << endl;
            }
        }
    }
};

int main() {
    try {
        vector<unique_ptr<thread>> threads;
        for(int i = 0; i < 5; i++) {
            auto task = make_unique<SleepingTask>(i);
            threads.emplace_back(make_unique<thread>([task = move(task)]() {
                task->run();
            }));
        }

        // �ȴ������߳����
        for (auto& t : threads) {
            t->join();
        }
    } catch(exception& e) {
        cerr << "main()�з����쳣: " << e.what() << endl;
    }

    return 0;
}