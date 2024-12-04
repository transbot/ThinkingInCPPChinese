//: C11:Interrupting_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �ж��������߳�
#include <iostream>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <chrono>

using namespace std;

class Blocked {
    // ԭ�ӱ��������ڱ���Ƿ��ж�
    atomic<bool> interrupted;

    // ���������������̼߳��֪ͨ
    condition_variable cv;

    // �����������ڱ�����������
    mutex mtx;

public:
    // ���캯������ʼ���жϱ�־Ϊfalse
    Blocked() : interrupted(false) {}

    // �߳����е���Ҫ����
    void run() {
        try {
            // ģ�������������ȴ�1�룩
            {
                unique_lock<mutex> lock(mtx);
                // ����ڵȴ������б��жϣ����׳��쳣
                if (cv.wait_for(lock, chrono::seconds(1)) == cv_status::no_timeout && interrupted.load()) {
                    throw runtime_error("����Interrupted_Exception");
                }
            }

            // �����ʾ��Ϣ��ģ���һ���������������ȴ��û����룩
            cout << "��run()�еȴ�cin.get():";
            {
                unique_lock<mutex> lock(mtx);
                // ����ڵȴ������б��жϣ����׳��쳣
                if (cv.wait_for(lock, chrono::seconds(10)) == cv_status::no_timeout && interrupted.load()) {
                    throw runtime_error("����Interrupted_Exception");
                }
            }
            // �ȴ��û�����
            cin.get();
        } catch (const runtime_error& e) {
            // �����쳣�������Ϣ�����˳�����
            cout << e.what() << endl;
        }
    }

    // �ж��̵߳ĺ���
    void interrupt() {
        // �����жϱ�־����֪ͨ���еȴ��е��߳�
        interrupted.store(true);
        cv.notify_all();
    }
};

int main(int argc, char* argv[]) {
    // ����Blocked����
    Blocked blocked;
    // �����������̣߳�����Blocked::run����
    thread t(&Blocked::run, &blocked);

    // ����ṩ�������в����������߳�˯��1.1��
    if (argc > 1) {
        this_thread::sleep_for(chrono::milliseconds(1100));
    }

    // �ж��߳�
    blocked.interrupt();

    // �ȴ��߳̽���
    t.join();

    return 0;
}
