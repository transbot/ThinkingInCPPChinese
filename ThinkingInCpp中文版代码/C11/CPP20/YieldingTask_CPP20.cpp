// C11:YieldingTask_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��yield()�����ʱ�л��߳�
#include <iostream>
#include <thread>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

class YieldingTask {
    int countDown;
    int id;

public:
    YieldingTask(int ident = 0) : countDown(5), id(ident) {}
    ~YieldingTask() {
        cout << id << " ���" << endl;
    }
    friend ostream& operator<<(ostream& os, const YieldingTask& yt) {
        return os << "#" << yt.id << ": " << yt.countDown;
    }
    void run() {
        while(true) {
            cout << *this << endl;
            if(--countDown == 0) return;
            this_thread::yield(); // �����̵߳������л��������߳�
        }
    }
};

int main() {
    try {
        vector<unique_ptr<thread>> threads;
        for(int i = 0; i < 5; i++) {
            auto task = make_unique<YieldingTask>(i);
            threads.emplace_back(make_unique<thread>([task = move(task)]() {
                task->run();
            }));
        }

        // �ȴ������߳����
        for (auto& t : threads) {
            t->join();
        }
    } catch(exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}