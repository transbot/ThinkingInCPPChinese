//: C09:Vendor.cpp {O}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��������Ѿ�������ˣ�ֻ���õ�.obj�ļ���
// �����޷�����Դ���롣
#include "Vendor.h"
#include <iostream>
using namespace std;

void Vendor::v() const { cout << "Vendor::v()" << endl; }
void Vendor::f() const { cout << "Vendor::f()" << endl; }
Vendor::~Vendor() { cout << "~Vendor()" << endl; }
void Vendor1::v() const { cout << "Vendor1::v()" << endl; }
void Vendor1::f() const { cout << "Vendor1::f()" << endl; }
Vendor1::~Vendor1() { cout << "~Vendor1()" << endl; }
void A(const Vendor& v) {
    // ...
    v.v();
    v.f();
    // ...
}

void B(const Vendor& v) {
    // ...
    v.v();
    v.f();
    // ...
} ///:~
