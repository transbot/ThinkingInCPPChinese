// C11:ConcurrentExecutor_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ���ִ�C++��׼��ʵ��������ZThread::ConcurrentExecutor�Ĺ���
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include "LiftOff_CPP20.h"

using namespace std;

class ConcurrentExecutor {
private:
    thread worker;
    queue<function<void()>> tasks;
    mutex queue_mutex;
    condition_variable condition;
    bool stop;

public:
    ConcurrentExecutor() : stop(false) {
        worker = thread([this] {
            while(true) {
                function<void()> task;
                {
                    unique_lock<mutex> lock(this->queue_mutex);
                    this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); });
                    if(this->stop && this->tasks.empty())
                        break;
                    task = move(this->tasks.front());
                    this->tasks.pop();
                }
                task(); // ִ������
            }
        });
    }

    ~ConcurrentExecutor() {
        {
            unique_lock<mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        worker.join(); // �ȴ������߳̽���
    }

    void execute(Runnable* task) {
        {
            unique_lock<mutex> lock(queue_mutex);
            if(stop)
                throw runtime_error("execute on stopped ConcurrentExecutor");
            tasks.emplace([task] {
                task->run();
                delete task; // �ͷ��������
            });
        }
        condition.notify_one(); // ֪ͨ�����߳�
    }
};

int main() {
    try {
        ConcurrentExecutor executor; // ����һ��ConcurrentExecutor����
        for(int i = 0; i < 5; i++) {
            executor.execute(new LiftOff(10, i)); // �ύ5��LiftOff����
        }
    } catch(const exception& e) {
        cerr << "�쳣: " << e.what() << endl; // ���񲢴�ӡ�쳣
    }
    cout << "�������������" << endl; // ��ӡ����������ɵ���Ϣ
    return 0;
}