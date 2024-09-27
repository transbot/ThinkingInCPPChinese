//: C01:Unexpected.cpp
// 演示异常规范与unexpected()
//{-msc} (无法正常终止)
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

// void g() {}         // 版本 1
void g() { throw 47; } // 版本 2

void my_unexpected() {
    cout << "抛出未预期的异常" << endl;
    exit(0);
}

int main() {
    set_unexpected(my_unexpected); // (忽略返回值)
    for(int i = 1; i <= 3; i++) {
        try {
            f(i);
        } catch(Up) {
            cout << "Up被捕获" << endl;
        } catch(Fit) {
            cout << "Fit被捕获" << endl;
        }
    }
} ///:~
