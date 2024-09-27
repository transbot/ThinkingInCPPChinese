//: C01:InitExcept.cpp {-bor}
// ���������Ӷ�����쳣��
#include <iostream>
using namespace std;

class Base {
    int i;
public:
    class BaseExcept {};
    Base(int i) : i(i) { throw BaseExcept(); }
};

class Derived : public Base {
public:
    class DerivedExcept {
        const char* msg;
    public:
        DerivedExcept(const char* msg) : msg(msg) {}
        const char* what() const { return msg; }
    };

    Derived(int j) try : Base(j) {
        // ���캯��������
        cout << "�ⲿ�ֲ����ӡ" << endl;
    } catch (BaseExcept&) {
        throw DerivedExcept("Base�Ӷ����׳����쳣");
    }
};

int main() {
    try {
        Derived d(3);
    } catch (Derived::DerivedExcept& d) {
        cout << d.what() << endl; // "Base�Ӷ����׳����쳣"
    }
} ///:~
