//: C05:StaticAssert2.cpp {-g++}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
using namespace std;

// 一个模板和一个特化
template<bool> struct StaticCheck {
    StaticCheck(...);
};
template<> struct StaticCheck<false> {};

// 宏（用于生成一个局部类）
#define STATIC_CHECK(expr, msg) { \
    class Error_##msg {}; \
    sizeof((StaticCheck<expr>(Error_##msg()))); \
}

// 检测缩小转换
template<class To, class From> To safe_cast(From from) {
    STATIC_CHECK(sizeof(From) <= sizeof(To), NarrowingConversion);
    return reinterpret_cast<To>(from);
}

int main() {
    void* p = 0;
    int i = safe_cast<int>(p);
    cout << "可以安全转换为int\n";
    //! char c = safe_cast<char>(p);
} ///:~
