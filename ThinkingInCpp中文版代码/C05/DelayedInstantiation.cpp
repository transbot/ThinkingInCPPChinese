//: C05:DelayedInstantiation.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 类模板的成员函数在需要时才实例化
class X {
public:
    void f() {}
};

class Y {
public:
    void g() {}
};

template<typename T> class Z {
    T t;
public:
    void a() { t.f(); }
    void b() { t.g(); }
};

int main() {
    Z<X> zx;
    zx.a(); // 不会创建 Z<X>::b()
    Z<Y> zy;
    zy.b(); // 不会创建 Z<Y>::a()
} ///:~
