//: C05:Lookup.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 只有使用某些特定编译器（例如，EDG和Metrowerks，并且后者要使用一个特殊选项），
// 程序才会表现出“预期”的行为。
#include <iostream>
using std::cout;
using std::endl;

// 传入double值时打印"f(double)"
void f(double) { cout << "f(double)" << endl; }

// 该模板类包含一个成员函数g。g函数调用了f函数，并传递值1
// 值1是double还是int？这是一个问题！
template<class T> class X {
public:
    void g() { f(1); }
};

// 传入int值时打印"f(int)"
void f(int) { cout << "f(int)" << endl; }

// main创建一个X<int>类型的对象，并立即调用它的成员函数g
// 如果编译器认为1是int，那么应该调用f(int)函数，即输出"f(int)"
// 如果编译器认为1是double，那么应该调用f(double)函数，即输出"f(double)"
int main() {
    X<int>().g();
} ///:~
