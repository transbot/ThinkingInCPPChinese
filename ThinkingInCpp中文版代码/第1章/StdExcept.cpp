//: C01:StdExcept.cpp
// ��std::runtime_error������һ���쳣��
#include <stdexcept>
#include <iostream>
using namespace std;

class MyError : public runtime_error {
public:
    MyError(const string& msg = "") : runtime_error(msg) {}
};

int main() {
    try {
        throw MyError("�ҵ���Ϣ");
    } catch(MyError& x) {
        cout << x.what() << endl;
    }
} ///:~
