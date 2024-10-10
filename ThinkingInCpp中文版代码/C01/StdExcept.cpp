//: C01:StdExcept.cpp
// 从std::runtime_error派生出一个异常类
#include <stdexcept>
#include <iostream>
using namespace std;

class MyError : public runtime_error {
public:
    MyError(const string& msg = "") : runtime_error(msg) {}
};

int main() {
    try {
        throw MyError("我的消息");
    } catch(MyError& x) {
        cout << x.what() << endl;
    }
} ///:~
