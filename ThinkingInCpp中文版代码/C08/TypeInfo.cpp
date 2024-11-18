//: C08:TypeInfo.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示typeid操作符
#include <iostream>
#include <typeinfo>
using namespace std;

struct PolyBase { virtual ~PolyBase() {} }; // 多态基类
struct PolyDer : PolyBase { PolyDer() {} }; // 多态派生类
struct NonPolyBase {}; // 非多态基类
struct NonPolyDer : NonPolyBase { NonPolyDer(int) {} }; // 非多态派生类

int main() {
    // 测试多态类型
    const PolyDer pd;
    const PolyBase* ppb = &pd;
    // 获取指针的类型信息
    cout << typeid(ppb).name() << endl;
    // 获取指针所指向对象的动态类型信息
    cout << typeid(*ppb).name() << endl;
    // 比较指针所指向对象的动态类型和pd的类型
    cout << boolalpha << (typeid(*ppb) == typeid(pd)) << endl;
    // 比较PolyDer和const PolyDer的类型
    cout << (typeid(PolyDer) == typeid(const PolyDer)) << endl;

    // 测试非多态类型
    const NonPolyDer npd(1);
    const NonPolyBase* nppb = &npd;
    // 获取指针的类型信息
    cout << typeid(nppb).name() << endl;
    // 获取指针所指向对象的静态类型信息
    cout << typeid(*nppb).name() << endl;
    // 比较指针所指向对象的静态类型和npd的类型
    cout << (typeid(*nppb) == typeid(npd)) << endl;

    // 测试内置类型
    int i;
    // 获取内置类型int的类型信息
    cout << typeid(i).name() << endl;
} ///:~
