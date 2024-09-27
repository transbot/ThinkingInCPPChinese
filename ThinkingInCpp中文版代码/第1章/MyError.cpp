//: C01:MyError.cpp {RunByHand}

class MyError {
    const char* const data;

public:
    MyError(const char* const msg = nullptr) : data(msg) {}
};

void f() {
    // 我们在这里“抛出”一个异常对象：
    throw MyError("发生了不好的事情");
}

int main() {
    // 稍后会讲到，需要在这里放一个“try 块”：
    f();
} ///:~
