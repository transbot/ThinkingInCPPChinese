//: C09:Dominance2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include <iostream>
using namespace std;

class A {
public:
    virtual ~A() {}
    virtual void f() { cout << "A::f\n"; }
};

class B : virtual public A {
public:
    void f() { cout << "B::f\n"; }
};

class C : public B {};
class D : public C, virtual public A {};

int main() {
    B* p = new D;
    p->f(); // 调用B::f()
    delete p;
} ///:~
