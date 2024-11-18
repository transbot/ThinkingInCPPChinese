//: C08:ConstructorOrder.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示构造和析构函数调用顺序
#include <iostream>
#include <typeinfo>
using namespace std;

template<int id>
class Announce {
public:
    Announce() {
        cout << typeid(*this).name() << " 构造函数" << endl;
    }
    ~Announce() {
        cout << typeid(*this).name() << " 析构函数" << endl;
    }
};

class X : public Announce<0> {
   // X类包含两个Announce类型的成员变量
    Announce<1> m1;
    Announce<2> m2;

public:
    X() { cout << "X::X()" << endl; }   // 构造函数
    ~X() { cout << "X::~X()" << endl; } // 析构函数
};

int main() {
    X x;
} ///:~
