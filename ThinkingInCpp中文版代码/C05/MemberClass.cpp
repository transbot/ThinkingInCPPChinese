//: C05:MemberClass.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示成员类模板
#include <iostream>
#include <typeinfo>
using namespace std;

template<class T>
class Outer {
public:
    template<class R>
    class Inner {
    public:
        void f();
    };
};

template<class T>
template<class R>
void Outer<T>::Inner<R>::f() {
    cout << "外层类 == " << typeid(T).name() << endl;
    cout << "内层类 == " << typeid(R).name() << endl;
    cout << "当前对象的完整类型名称 == " << typeid(*this).name() << endl;
}

int main() {
    Outer<int>::Inner<bool> inner;
    inner.f();
} ///:~
