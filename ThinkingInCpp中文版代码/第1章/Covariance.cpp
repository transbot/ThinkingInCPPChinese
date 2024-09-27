//: C01:Covariance.cpp {-xo}
// 应当导致编译错误{-mwcc}{-msc}

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
    // 保持异常规范与基类一致
    void f() throw(DerivedException) {
        throw BaseException();
    }

    virtual void g() throw(DerivedException) {
        throw DerivedException();
    }
}; 

int main() {
    // 空的 main 函数入口点，不执行任何操作
    return 0;
}

///:~


