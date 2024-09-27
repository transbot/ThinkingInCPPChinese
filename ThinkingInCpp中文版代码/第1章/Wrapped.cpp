//: C01:Wrapped.cpp
// ��ȫ�ġ�ԭ�ӻ���ָ��
#include <iostream>
#include <cstddef>
using namespace std;

// ����Ӽ��ˣ�����Կ����ṩ��������
template <class T, int sz = 1> class PWrap {
    T* ptr;

public:
    class RangeError {}; // �쳣��

    PWrap() {
        ptr = new T[sz];
        cout << "PWrap��Ĺ��캯��" << endl;
    }

    ~PWrap() {
        delete[] ptr;
        cout << "PWrap�����������" << endl;
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
        cout << "����һֻ��" << endl;
        throw 47;
    }

    void operator delete[](void* p) {
        cout << "ȡ�����䣨�ͷţ�һֻ��" << endl;
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
        cout << "�ѽ����쳣�������" << endl;
    } catch (...) {
        cout << "�ѽ���catch(...)" << endl;
    }
} ///:~
