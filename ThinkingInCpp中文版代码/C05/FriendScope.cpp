//: C05:FriendScope.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
using namespace std;

class Friendly {
    int i;
public:
    Friendly(int theInt) { i = theInt; }
    friend void f(const Friendly&); // 需要全局定义
    void g() { f(*this); }
};

void h() { f(Friendly(1)); } // ADL机制介入

void f(const Friendly& fo) { // 友元定义
    cout << fo.i << endl;
}

int main() {
    h(); // 输出1
    Friendly(2).g(); // 输出2
} ///:~
