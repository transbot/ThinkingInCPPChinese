//: C09:Dominance2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

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
    p->f(); // ����B::f()
    delete p;
} ///:~
