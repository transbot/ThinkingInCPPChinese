//: C01:BadException.cpp {-bor}
#include <exception> // 为了 std::bad_exception
#include <iostream>
#include <cstdio>
using namespace std;

// 异常类:
class A {};
class B {};

// terminate()处理程序
void my_thandler() {
    cout << "terminate被调用" << endl;
    exit(0);
}

// unexpected()处理程序
void my_uhandler1() { throw A(); }
void my_uhandler2() { throw; }

// 如果将此throw语句嵌入到 f 或 g 中，
// 那么编译器会检测到违反异常规范，并报告错误。
// 因此，我们将其放在自己的函数中。
void t() { throw B(); }
void f() throw(A) { t(); }
void g() throw(A, bad_exception) { t(); }

int main() {
    set_terminate(my_thandler);
    set_unexpected(my_uhandler1);

    try {
        f();
    } catch(A&) {
        cout << "从f捕获了一个A" << endl;
    }

    set_unexpected(my_uhandler2);

    try {
        g();
    } catch(bad_exception&) {
        cout << "从g捕获了一个bad_exception" << endl;
    }

    try {
        f();
    } catch(...) {
        cout << "这段话永远不会显示" << endl;
    }
} ///:~
