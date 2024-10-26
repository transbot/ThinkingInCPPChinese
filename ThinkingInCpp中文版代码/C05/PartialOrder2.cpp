//: C05:PartialOrder2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示类模板的部分排序（偏序）
#include <iostream>
using namespace std;

template<class T, class U> class C {
public:
    void f() { cout << "主模板\n"; }
};

template<class U> class C<int, U> {
public:
    void f() { cout << "T == int\n"; }
};

template<class T> class C<T, double> {
public:
    void f() { cout << "U == double\n"; }
};

template<class T, class U> class C<T*, U> {
public:
    void f() { cout << "使用了T*\n"; }
};

template<class T, class U> class C<T, U*> {
public:
    void f() { cout << "使用了U*\n"; }
};

template<class T, class U> class C<T*, U*> {
public:
    void f() { cout << "使用了T*和U*\n"; }
};

template<class T> class C<T, T> {
public:
    void f() { cout << "T == U\n"; }
};

int main() {
    C<float, int>().f();      // 1: 主模板
    C<int, float>().f();      // 2: T == int
    C<float, double>().f();   // 3: U == double
    C<float, float>().f();    // 4: T == U
    C<float*, float>().f();   // 5: 使用了T* [T是float]
    C<float, float*>().f();   // 6: 使用了U* [U是float]
    C<float*, int*>().f();    // 7: 使用了T*和U* [float, int]

    // 以下情况存在歧义：
    // 8: C<int, int>().f();
    // 9: C<double, double>().f();
    // 10: C<float*, float*>().f();
    // 11: C<int, int*>().f();
    // 12: C<int*, int*>().f();
} ///:~
