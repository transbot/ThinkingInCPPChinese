//: C01:Unexpected.cpp
// 演示异常规范与 unexpected()
//{-msc} (无法正常终止)
#include <exception>
#include <iostream>
using namespace std;

void my_unexpected() {
    cout << "抛出未预期的异常" << endl;
    exit(0);
}

void f() throw(int) {  // 异常规范声明只抛出 int 类型的异常
    throw 5;  // 实际抛出int类型的异常，不违反规范
}

void g() throw(double) {  // 异常规范声明只抛出double类型的异常
        throw 5;  // 违反了规范
    }


int main() {
    set_unexpected(my_unexpected); // (忽略返回值) 

    // 捕获正常的异常 
    try {
        f();  // 调用f()
    } catch(int) {
        cout << "正常捕获了int类型的异常" << endl;
    }

    // 捕获未处理的异常
    try {
        g();  // 调用g()
    } catch(...) {
        cout << "捕获了未预期的异常" << endl;
    }

} ///:~