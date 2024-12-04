//: C10:ProxyDemo.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 代理模式的简单演示
#include <iostream>
using namespace std;

// 定义一个基类，所有代理和实现类都需要实现这个基类所规范的接口
class ProxyBase {
public:
    virtual void f() = 0;   // 纯虚函数，子类必须实现
    virtual void g() = 0;   // 纯虚函数，子类必须实现
    virtual void h() = 0;   // 纯虚函数，子类必须实现
    virtual ~ProxyBase() {} // 虚析构函数，确保派生类的析构函数被正确调用
};

// 实现类，继承自ProxyBase，实现了所有纯虚函数
class Implementation : public ProxyBase {
public:
    void f() { cout << "Implementation.f()" << endl; } // 实现f()函数
    void g() { cout << "Implementation.g()" << endl; } // 实现g()函数
    void h() { cout << "Implementation.h()" << endl; } // 实现h()函数
};

// 代理类，继承自ProxyBase，容纳了实现类的指针
class Proxy : public ProxyBase {
    ProxyBase* implementation; // 容纳实现类的指针
public:
    Proxy() { implementation = new Implementation(); } // 在构造函数中创建实现类对象
    ~Proxy() { delete implementation; } // 在析构函数中释放实现类对象

    // 将调用转发给实现类
    void f() { implementation->f(); } // 转发f()调用
    void g() { implementation->g(); } // 转发g()调用
    void h() { implementation->h(); } // 转发h()调用
};

int main() {
    Proxy p; // 创建代理对象
    p.f(); // 通过代理对象调用f()
    p.g(); // 通过代理对象调用g()
    p.h(); // 通过代理对象调用h()
} ///:~