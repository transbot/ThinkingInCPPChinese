//: C09:Vendor.cpp {O}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 假设这个已经编译好了，只能拿到.obj文件，
// 我们无法访问源代码。
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
