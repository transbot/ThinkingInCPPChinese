//: C01:Rawp.cpp
// ��ʾ��ָ��
#include <iostream>
#include <cstddef>
using namespace std;

// è��
class Cat {
public:
    Cat() { cout << "Cat()" << endl; }
    ~Cat() { cout << "~Cat()" << endl; }
};

// ����
class Dog {
public:
    void* operator new(size_t sz) {
        cout << "����һֻ��" << endl;
        throw 47;
    }
    void operator delete(void* p) {
        cout << "ȡ�����䣨�ͷţ�һֻ��" << endl;
        ::operator delete(p);
    }
};

// �����ʹ������Դ
class UseResources {
public:
    Cat* bp;
    Dog* op;
    UseResources(int count = 1) {
        cout << "UseResources()" << endl;
        bp = new Cat[count];
        op = new Dog;
    }
    ~UseResources() {
        cout << "~UseResources()" << endl;
        delete [] bp; // ����ɾ������
        delete op;
    }
};

int main() {
    try {
        UseResources ur(3); // ��ͼ������ֻè��һֻ��
    } catch(int) {
        cout << "�ѽ����쳣�������" << endl;
    }
}
