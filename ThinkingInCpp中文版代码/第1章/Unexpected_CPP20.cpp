//: C01:Unexpected.cpp
// ��ʾ�쳣�淶�� unexpected()
//{-msc} (�޷�������ֹ)
#include <exception>
#include <iostream>
using namespace std;

void my_unexpected() {
    cout << "�׳�δԤ�ڵ��쳣" << endl;
    exit(0);
}

void f() throw(int) {  // �쳣�淶����ֻ�׳� int ���͵��쳣
    throw 5;  // ʵ���׳�int���͵��쳣����Υ���淶
}

void g() throw(double) {  // �쳣�淶����ֻ�׳�double���͵��쳣
        throw 5;  // Υ���˹淶
    }


int main() {
    set_unexpected(my_unexpected); // (���Է���ֵ) 

    // �����������쳣 
    try {
        f();  // ����f()
    } catch(int) {
        cout << "����������int���͵��쳣" << endl;
    }

    // ����δ������쳣
    try {
        g();  // ����g()
    } catch(...) {
        cout << "������δԤ�ڵ��쳣" << endl;
    }

} ///:~