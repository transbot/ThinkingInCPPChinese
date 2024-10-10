//: C01:Unexpected.cpp
// ��ʾ�쳣�淶��unexpected()
//{-msc} (�޷�������ֹ)
#include <exception>
#include <iostream>
using namespace std;

class Up {};
class Fit {};

void g();

void f(int i) throw(Up, Fit) {
    switch(i) {
        case 1: throw Up();
        case 2: throw Fit();
    }
    g();
}

// void g() {}         // �汾 1
void g() { throw 47; } // �汾 2

void my_unexpected() {
    cout << "�׳�δԤ�ڵ��쳣" << endl;
    exit(0);
}

int main() {
    set_unexpected(my_unexpected); // (���Է���ֵ)
    for(int i = 1; i <= 3; i++) {
        try {
            f(i);
        } catch(Up) {
            cout << "Up������" << endl;
        } catch(Fit) {
            cout << "Fit������" << endl;
        }
    }
} ///:~
