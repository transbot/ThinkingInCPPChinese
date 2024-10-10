//: C01:Terminator.cpp
// 使用set_terminate()，同时演示“未捕获的异常”。
#include <exception>
#include <iostream>
using namespace std;

// 这是一个自定义的terminate()
void terminator() {
    cout << "I'll be back!" << endl;
    exit(0);
}

void (*old_terminate)() = set_terminate(terminator);

class Botch {
public:
    class Fruit {};
    
    void f() {
        cout << "Botch::f()" << endl;
        throw Fruit();
    }
    
    ~Botch() { throw 'c'; }
};

int main() {
    try {
        Botch b;
        b.f();
    } catch(...) {
        cout << "当前在catch(...)处理程序中" << endl;
    }
} ///:~
