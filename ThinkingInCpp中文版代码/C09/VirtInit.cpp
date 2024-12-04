//: C09:VirtInit.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示当有虚基类时的初始化顺序
#include <iostream>
#include <string>
using namespace std;

class M {
public:
    M(const string& s) { cout << "M " << s << endl; }
};

class A {
    M m;
public:
    A(const string& s) : m("in A") {
        cout << "A " << s << endl;
    }
    virtual ~A() {}
};

class B {
    M m;
public:
    B(const string& s) : m("in B") {
        cout << "B " << s << endl;
    }
    virtual ~B() {}
};

class C {
    M m;
public:
    C(const string& s) : m("in C") {
        cout << "C " << s << endl;
    }
    virtual ~C() {}
};

class D {
    M m;
public:
    D(const string& s) : m("in D") {
        cout << "D " << s << endl;
    }
    virtual ~D() {}
};

// 多重继承自A、虚继承自B和C
class E : public A, virtual public B, virtual public C {
    M m;
public:
    E(const string& s) : A("from E"), B("from E"), C("from E"), m("in E") {
        cout << "E " << s << endl;
    }
};

// 虚继承自B和C，多重继承自D
class F : virtual public B, virtual public C, public D {
    M m;
public:
    F(const string& s) : B("from F"), C("from F"), D("from F"), m("in F") {
        cout << "F " << s << endl;
    }
};

// 多重继承自E和F
class G : public E, public F {
    M m;
public:
    G(const string& s) :
        B("from G"), C("from G"), E("from G"), F("from G"), m("in G") {
        cout << "G " << s << endl;
    }
};

int main() {
    G g("from main");
} ///:~
