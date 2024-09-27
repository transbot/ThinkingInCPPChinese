//: C01:Terminator.cpp
// ʹ��set_terminate()��ͬʱ��ʾ��δ������쳣����
#include <exception>
#include <iostream>
using namespace std;

// ����һ���Զ����terminate()
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
        cout << "��ǰ��catch(...)���������" << endl;
    }
} ///:~
