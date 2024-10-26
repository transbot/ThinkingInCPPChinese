//: C05:Lookup2.cpp {-bor}{-g++}{-dmc}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// MSVC编译器请使用选项-Za （ANSI 模式）
#include <algorithm>
#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;

void g() { cout << "全局g()" << endl; }

template<class T> class Y {
public:
    void g() {
        cout << "Y<" << typeid(T).name() << ">::g()" << endl;
    }
    
    void h() {
        cout << "Y<" << typeid(T).name() << ">::h()" << endl;
    }    
    typedef int E;
};

typedef double E;

template<class T> void swap(T& t1, T& t2) {
    cout << "全局swap" << endl;
    T temp = t1;
    t1 = t2;
    t2 = temp;
}

template<class T> class X : public Y<T> {
public:
    E f() {
        g();
        this->h();
        T t1 = T(), t2 = T(1);
        cout << t1 << endl;
        swap(t1, t2);
        std::swap(t1, t2);
        cout << typeid(E).name() << endl;
        return E(t2);
    }
};

int main() {
    X<int> x;
    cout << x.f() << endl;
} ///:~
