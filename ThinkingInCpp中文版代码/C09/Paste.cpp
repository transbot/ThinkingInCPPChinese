//: C09:Paste.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
//{L} Vendor

// ʹ�ö��ؼ̳���ʰ��̯��
#include <iostream>
#include "Vendor.h"
using namespace std;

class MyBase { // �޸�Vendor�ӿ�
public:
    virtual void v() const = 0;
    virtual void f() const = 0;
    // �µĽӿں���:
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
    MyBase& mp = p1p; // ����ת��
    cout << "����f()" << endl;
    mp.f(); // ��ȷ����Ϊ
    cout << "����g()" << endl;
    mp.g(); // �µ���Ϊ
    cout << "����A(p1p)" << endl;
    A(p1p); // �ɵ���Ϊ
    cout << "����B(p1p)" << endl;
    B(p1p); // �ɵ���Ϊ
    cout << "delete mp" << endl;
    // delete�Ѷ�������:
    delete &mp; // ��ȷ����Ϊ
} ///:~
