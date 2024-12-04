// C11:SimplePriorities_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ�߳����ȼ���ʹ�ã�Windows��
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <windows.h>

using namespace std;

const double pi = 3.14159265358979323846;
const double e = 2.7182818284590452354;

class SimplePriorities {
    int countDown;
    volatile double d; // �������Ż�
    int id;

public:
    SimplePriorities(int ident = 0) : countDown(5), id(ident) {}
    ~SimplePriorities() {
        cout << id << " ���" << endl;
    }
    friend ostream& operator<<(ostream& os, const SimplePriorities& sp) {
        return os << "#" << sp.id << " ���ȼ�: " 
                  << GetThreadPriority(GetCurrentThread()) << " ����: " << sp.countDown;
    }
    void run() {
        while(true) {
            // ִ�к�ʱ�ҿ����жϵĲ���
            for(int i = 1; i < 100000; i++)
                d = d + (pi + e) / double(i);
            cout << *this << endl;
            if(--countDown == 0) return;
        }
    }
};

bool setThreadPriority(std::thread& t, int priority) {
    if (SetThreadPriority(t.native_handle(), priority) == 0) {
        cerr << "�߳����ȼ�����ʧ��: " << GetLastError() << endl;
        return false;
    }
    return true;
}

void highPriorityTask() {
    SimplePriorities sp;
    sp.run();
}

void lowPriorityTask(int id) {
    SimplePriorities sp(id);
    sp.run();
}

int main() {
    try {
        vector<thread> threads;

        // ���������ȼ��߳�
        thread high(highPriorityTask);
        if (!setThreadPriority(high, THREAD_PRIORITY_HIGHEST)) {
            cerr << "���߳����ȼ�����Ϊ���ߡ�ʧ�ܡ�" << endl;
        }
        threads.push_back(move(high));

        // ���������ȼ��߳�
        for(int i = 0; i < 5; i++) {
            thread low(lowPriorityTask, i);
            if (!setThreadPriority(low, THREAD_PRIORITY_LOWEST)) {
                cerr << "���߳����ȼ�����Ϊ���͡�ʧ�ܡ�" << endl;
            }
            threads.push_back(move(low));
        }

        // �ȴ������߳����
        for (auto& t : threads) {
            if (t.joinable()) {
                t.join();
            }
        }
    } catch(exception& e) {
        cerr << "main()�з����쳣: " << e.what() << endl;
    }

    return 0;
}