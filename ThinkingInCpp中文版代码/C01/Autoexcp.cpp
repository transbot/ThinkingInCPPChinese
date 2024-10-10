//: C01:Autoexcp.cpp
// 即使提供了类型转换构造函数，也不会自动执行类型转换，
#include <iostream>
using namespace std;

class Except1 {};
class Except2 {
public:
    // 转换构造函数
    Except2(const Except1&) {}
};

void f() { throw Except1(); }

int main() {
    try {
        f();
    } catch(Except2&) {
        cout << "当前在Except2处理程序中" << endl;
    } catch(Except1&) {
        cout << "当前在Except1处理程序中" << endl;
    }
} ///:~
