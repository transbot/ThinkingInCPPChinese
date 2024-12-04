//: C09:Paste.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} Vendor

// 使用多重继承收拾烂摊子
#include <iostream>
#include "Vendor.h"
using namespace std;

class MyBase { // 修复Vendor接口
public:
    virtual void v() const = 0;
    virtual void f() const = 0;
    // 新的接口函数:
    virtual void g() const = 0;
    virtual ~MyBase() { cout << "~MyBase()" << endl; }
};

class Paste1 : public MyBase, public Vendor1 {
public:
    void v() const {
        cout << "Paste1::v()" << endl;
        Vendor1::v();
    }
    void f() const {
        cout << "Paste1::f()" << endl;
        Vendor1::f();
    }
    void g() const { cout << "Paste1::g()" << endl; }
    ~Paste1() { cout << "~Paste1()" << endl; }
};

int main() {
    Paste1& p1p = *new Paste1;
    MyBase& mp = p1p; // 向上转型
    cout << "调用f()" << endl;
    mp.f(); // 正确的行为
    cout << "调用g()" << endl;
    mp.g(); // 新的行为
    cout << "调用A(p1p)" << endl;
    A(p1p); // 旧的行为
    cout << "调用B(p1p)" << endl;
    B(p1p); // 旧的行为
    cout << "delete mp" << endl;
    // delete堆对象引用:
    delete &mp; // 正确的行为
} ///:~
