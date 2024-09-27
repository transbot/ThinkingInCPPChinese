//: C01:Basexcpt.cpp
// �쳣��νṹ��
#include <iostream>
using namespace std;

class X {
public:
    class Trouble {};
    class Small : public Trouble {};
    class Big : public Trouble {};
    void f() { throw Big(); }
};

int main() {
    X x;
    try {
        x.f();
    } catch(X::Trouble&) {
        cout << "����Trouble" << endl;
        // ��ǰ��Ĵ��������أ�
    } catch(X::Small&) {
        cout << "����Small Trouble" << endl;
    } catch(X::Big&) {
        cout << "����Big Trouble" << endl;
    }
} ///:~
