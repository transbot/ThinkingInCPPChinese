//: C11:Interrupting3.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// �ж�����ʱ��ȡ�Ĺ��÷�
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

const double PI = 3.14159265358979323846;
const double E = 2.7182818284590452354;

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

class Blocked3 : public Runnable {
    volatile double d;
public:
    Blocked3() : d(0.0) {}
    void run() {
        try {
            while(!Thread::interrupted()) {
                point1:  // λ��1
                NeedsCleanup n1(1);
                cout << "����˯��" << endl;
                Thread::sleep(1000);
                point2:  // λ��2
                NeedsCleanup n2(2);
                cout << "���ڼ���" << endl;
                // һ����ʱ�ķ�����������
                for(int i = 1; i < 100000; i++)
                    d = d + (PI + E) / (double)i;
            }
            cout << "ͨ��while()�����˳�" << endl;
        } catch(Interrupted_Exception&) {
            cout << "ͨ������Interrupted_Exception�˳�" << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cerr << "�÷�: " << argv[0] << " �ӳٺ�����" << endl;
        exit(1);
    }
    int delay = atoi(argv[1]);
    try {
        Thread t(new Blocked3);
        Thread::sleep(delay);
        t.interrupt();
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
