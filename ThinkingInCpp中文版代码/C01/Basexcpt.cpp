//: C01:Basexcpt.cpp
// 异常层次结构。
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
        cout << "捕获Trouble" << endl;
        // 被前面的处理器隐藏：
    } catch(X::Small&) {
        cout << "捕获Small Trouble" << endl;
    } catch(X::Big&) {
        cout << "捕获Big Trouble" << endl;
    }
} ///:~
