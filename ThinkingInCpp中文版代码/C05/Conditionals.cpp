//: C05:Conditionals.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用编译时条件来选择执行的代码
#include <iostream>
using namespace std;

template<bool cond> struct Select {};

// true特化
template<> class Select<true> {
    static void statement1() {
        cout << "正在执行语句1 – statement1\n";
    }
public:
    static void f() {
        statement1();
    }
};

// false特化
template<> class Select<false> {
    static void statement2() {
        cout << "正在执行语句2 - statement2\n";
    }
public:
    static void f() {
        statement2();
    }
};

template<bool cond> void execute() {
    Select<cond>::f();
}

int main() {
    // int类型的大小确实为4个字节 
    execute<sizeof(int) == 4>();
} ///:~
