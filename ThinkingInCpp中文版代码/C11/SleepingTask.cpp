//: C11:SleepingTask.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����sleep()����ͣһ��ʱ��
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/ThreadedExecutor.h"

using namespace ZThread;
using namespace std;

class SleepingTask : public Runnable {
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
                Thread::sleep(100); // ��ͣ100����
            } catch(Interrupted_Exception& e) {
                cerr << e.what() << endl;
            }
        }
    }
};

int main() {
    try {
        ThreadedExecutor executor;
        for(int i = 0; i < 5; i++)
            executor.execute(new SleepingTask(i));
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
