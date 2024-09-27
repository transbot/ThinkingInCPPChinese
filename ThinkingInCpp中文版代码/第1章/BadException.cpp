//: C01:BadException.cpp {-bor}
#include <exception> // Ϊ�� std::bad_exception
#include <iostream>
#include <cstdio>
using namespace std;

// �쳣��:
class A {};
class B {};

// terminate()�������
void my_thandler() {
    cout << "terminate������" << endl;
    exit(0);
}

// unexpected()�������
void my_uhandler1() { throw A(); }
void my_uhandler2() { throw; }

// �������throw���Ƕ�뵽 f �� g �У�
// ��ô���������⵽Υ���쳣�淶�����������
// ��ˣ����ǽ�������Լ��ĺ����С�
void t() { throw B(); }
void f() throw(A) { t(); }
void g() throw(A, bad_exception) { t(); }

int main() {
    set_terminate(my_thandler);
    set_unexpected(my_uhandler1);

    try {
        f();
    } catch(A&) {
        cout << "��f������һ��A" << endl;
    }

    set_unexpected(my_uhandler2);

    try {
        g();
    } catch(bad_exception&) {
        cout << "��g������һ��bad_exception" << endl;
    }

    try {
        f();
    } catch(...) {
        cout << "��λ���Զ������ʾ" << endl;
    }
} ///:~
