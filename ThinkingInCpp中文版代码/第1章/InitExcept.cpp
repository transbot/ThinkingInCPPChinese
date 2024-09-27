//: C01:InitExcept.cpp {-bor}
// 处理来自子对象的异常。
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
        // 构造函数的主体
        cout << "这部分不会打印" << endl;
    } catch (BaseExcept&) {
        throw DerivedExcept("Base子对象抛出了异常");
    }
};

int main() {
    try {
        Derived d(3);
    } catch (Derived::DerivedExcept& d) {
        cout << d.what() << endl; // "Base子对象抛出了异常"
    }
} ///:~
