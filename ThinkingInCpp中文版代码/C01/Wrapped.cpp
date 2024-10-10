//: C01:Wrapped.cpp
// 安全的、原子化的指针
#include <iostream>
#include <cstddef>
using namespace std;

// 这里从简了，你可以考虑提供其他参数
template <class T, int sz = 1> class PWrap {
    T* ptr;

public:
    class RangeError {}; // 异常类

    PWrap() {
        ptr = new T[sz];
        cout << "PWrap类的构造函数" << endl;
    }

    ~PWrap() {
        delete[] ptr;
        cout << "PWrap类的析构函数" << endl;
    }

    T& operator[](int i) throw(RangeError) {
        if (i >= 0 && i < sz) return ptr[i];
        throw RangeError();
    }
};

class Cat {
public:
    Cat() { cout << "Cat()" << endl; }
    ~Cat() { cout << "~Cat()" << endl; }
    void g() {}
};

class Dog {
public:
    void* operator new[](size_t) {
        cout << "分配一只狗" << endl;
        throw 47;
    }

    void operator delete[](void* p) {
        cout << "取消分配（释放）一只狗" << endl;
        ::operator delete[](p);
    }
};

class UseResources {
    PWrap<Cat, 3> cats;
    PWrap<Dog> dog;

public:
    UseResources() { cout << "UseResources()" << endl; }
    ~UseResources() { cout << "~UseResources()" << endl; }
    void f() { cats[1].g(); }
};

int main() {
    try {
        UseResources ur;
    } catch (int) {
        cout << "已进入异常处理程序" << endl;
    } catch (...) {
        cout << "已进入catch(...)" << endl;
    }
} ///:~
