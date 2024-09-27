//: C01:Covariance.cpp {-xo}
// Ӧ�����±������{-mwcc}{-msc}

#include <iostream>
using namespace std;

class Base {
public:
    class BaseException {};
    class DerivedException : public BaseException {};
    virtual void f() throw(DerivedException) {
        throw DerivedException();
    }

    virtual void g() throw(BaseException) {
        throw BaseException();
    }
};

class Derived : public Base {
public:
    // �����쳣�淶�����һ��
    void f() throw(DerivedException) {
        throw BaseException();
    }

    virtual void g() throw(DerivedException) {
        throw DerivedException();
    }
}; 

int main() {
    // �յ� main ������ڵ㣬��ִ���κβ���
    return 0;
}

///:~


