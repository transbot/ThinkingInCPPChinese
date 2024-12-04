// C11:PoolExecutor_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ���ִ�C++��׼��ʵ��һ���򵥵��̳߳�
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include "LiftOff_CPP20.h"

using namespace std;

class PoolExecutor {
private:
    vector<thread> workers; // �洢�����̵߳�����
    queue<function<void()>> tasks; // �洢����Ķ���
    mutex queue_mutex; // ����������еĻ�����
    condition_variable condition; // ���������������̼߳��ͬ��
    bool stop; // ������־����ʾ�̳߳��Ƿ�ֹͣ

public:
    // ���캯������ʼ���̳߳�
    PoolExecutor(size_t num_threads) : stop(false) {
        for(size_t i = 0; i < num_threads; ++i) {
            workers.emplace_back([this] {
                while(true) {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(this->queue_mutex); // ��ȡ������
                        this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); }); // �ȴ������ֹͣ�ź�
                        if(this->stop && this->tasks.empty())
                            break; // ����̳߳�ֹͣ���������Ϊ�գ����˳�ѭ��
                        task = move(this->tasks.front()); // ȡ������
                        this->tasks.pop(); // ������������Ƴ�����
                    }
                    task(); // ִ������
                }
            });
        }
    }

    // ����������ȷ�������߳��ڶ�������ʱ���ѽ���
    ~PoolExecutor() {
        {
            unique_lock<mutex> lock(queue_mutex); // ��ȡ������
            stop = true; // ����ֹͣ��־
        }
        condition.notify_all(); // ֪ͨ���еȴ����߳�
        for(thread& worker : workers)
            worker.join(); // �ȴ����й����߳̽���
    }

    // �ύ�����̳߳�
    void execute(Runnable* task) {
        {
            unique_lock<mutex> lock(queue_mutex); // ��ȡ������
            if(stop)
                throw runtime_error("����ֹͣ��PoolExecutor��ִ��"); // ����̳߳���ֹͣ���׳��쳣
            tasks.emplace([task] {
                task->run(); // ִ������
                delete task; // �ͷ��������
            });
        }
        condition.notify_one(); // ֪ͨһ���ȴ����߳�
    }
};

int main() {
    try {
        PoolExecutor executor(5); // ����һ������5���̵߳��̳߳�
        for(int i = 0; i < 5; i++) {
            executor.execute(new LiftOff(10, i)); // �ύ5��LiftOff����
        }
    } catch(const exception& e) {
        cerr << "�쳣: " << e.what() << endl; // ���񲢴�ӡ�쳣
    }
    cout << "�������������" << endl; // ��ӡ����������ɵ���Ϣ
    return 0;
}