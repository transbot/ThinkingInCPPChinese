//: C01:Autoexcp.cpp
// ��ʹ�ṩ������ת�����캯����Ҳ�����Զ�ִ������ת����
#include <iostream>
using namespace std;

class Except1 {};
class Except2 {
public:
    // ת�����캯��
    Except2(const Except1&) {}
};

void f() { throw Except1(); }

int main() {
    try {
        f();
    } catch(Except2&) {
        cout << "��ǰ��Except2���������" << endl;
    } catch(Except1&) {
        cout << "��ǰ��Except1���������" << endl;
    }
} ///:~
