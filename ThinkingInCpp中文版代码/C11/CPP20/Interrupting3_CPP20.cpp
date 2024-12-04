//: C11:Interrupting3_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �ж�����ʱ��ȡ�Ĺ��÷�
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <cstdlib>
#include <condition_variable>
#include <mutex>

using namespace std;

const double PI = 3.14159265358979323846;
const double E = 2.7182818284590452354;

// NeedsCleanup�࣬����ģ����Դ����
class NeedsCleanup {
    int id;
public:
    NeedsCleanup(int ident) : id(ident) {
        cout << "NeedsCleanup " << id << endl;
    }
    ~NeedsCleanup() {
        cout << "~NeedsCleanup " << id << endl;
    }
};

// Blocked3�࣬ģ����Ա��жϵ�����
class Blocked3 {
    atomic<bool> interrupted; // �жϱ�־
    volatile double d; // �������
    mutex mtx;
    condition_variable cv;

public:
    Blocked3() : interrupted(false), d(0.0) {}

    void run() {
        try {
            while (!interrupted.load()) {
                NeedsCleanup n1(1);
                cout << "����˯��" << endl;
                {
                    unique_lock<mutex> lock(mtx);
                    if (cv.wait_for(lock, chrono::seconds(1), [this] { return interrupted.load(); })) {
                        throw runtime_error("ͨ������Interrupted_Exception�˳�");
                    }
                }

                NeedsCleanup n2(2);
                cout << "���ڼ���" << endl;
                // һ����ʱ�ķ���������
                for (int i = 1; i < 100000; i++)
                    d = d + (PI + E) / (double)i;
            }
            cout << "ͨ��while()�����˳�" << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    void interrupt() {
        interrupted.store(true);
        cv.notify_all(); // ֪ͨ����������ȷ��������wait�������
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "�÷�: " << argv[0] << " �ӳٺ�����" << endl;
        exit(1);
    }
    int delay = atoi(argv[1]);

    Blocked3 blocked3;

    // �����������̣߳�����Blocked3::run����
    thread t(&Blocked3::run, &blocked3);

    // ���߳�˯��ָ���ĺ�����
    this_thread::sleep_for(chrono::milliseconds(delay));

    // �ж��߳�
    blocked3.interrupt();

    // �ȴ��߳̽���
    t.join();

    return 0;
}
