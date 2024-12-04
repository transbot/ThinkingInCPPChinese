//: C09:VirtInit.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ���������ʱ�ĳ�ʼ��˳��
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

// ���ؼ̳���A����̳���B��C
class E : public A, virtual public B, virtual public C {
    M m;
public:
    E(const string& s) : A("from E"), B("from E"), C("from E"), m("in E") {
        cout << "E " << s << endl;
    }
};

// ��̳���B��C�����ؼ̳���D
class F : virtual public B, virtual public C, public D {
    M m;
public:
    F(const string& s) : B("from F"), C("from F"), D("from F"), m("in F") {
        cout << "F " << s << endl;
    }
};

// ���ؼ̳���E��F
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
