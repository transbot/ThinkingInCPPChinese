//: C01:Cleanup.cpp
// �׳��쳣��ֻ���ѹ�����ϵĶ���Żᱻ����
#include <iostream>
using namespace std;

class Trace {    
    static int counter;  // ȫ��int������
    int objid;
public:
    Trace() {
        objid = counter++;
        cout << "���ڹ���Trace����#" << objid << endl;
        if (objid == 3) throw 3;
    }

    ~Trace() {
        cout << "��������Trace����#" << objid << endl;
    }
};

int Trace::counter = 0;

int main() {
    try {
        Trace n1;

        // ����Trace��������Ĺ������׳����쳣��
        Trace array[5];

        Trace n2; // ��Զִ�в�������
    } catch (int i) {
        cout << "����" << i << endl;
    }
} ///:~
