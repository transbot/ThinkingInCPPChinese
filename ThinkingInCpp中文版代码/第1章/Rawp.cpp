//: C01:Rawp.cpp
// 演示裸指针
#include <iostream>
#include <cstddef>
using namespace std;

// 猫类
class Cat {
public:
    Cat() { cout << "Cat()" << endl; }
    ~Cat() { cout << "~Cat()" << endl; }
};

// 狗类
class Dog {
public:
    void* operator new(size_t sz) {
        cout << "分配一只狗" << endl;
        throw 47;
    }
    void operator delete(void* p) {
        cout << "取消分配（释放）一只狗" << endl;
        ::operator delete(p);
    }
};

// 这个类使用了资源
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
        delete [] bp; // 数组删除命令
        delete op;
    }
};

int main() {
    try {
        UseResources ur(3); // 试图创建三只猫和一只狗
    } catch(int) {
        cout << "已进入异常处理程序" << endl;
    }
}
