//: C05:FriendScope2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include <iostream>
using namespace std;

// 必要的前置（前向）声明:
template<class T> class Friendly;
template<class T> void f(const Friendly<T>&);

template<class T> class Friendly {
    T t;
public:
    Friendly(const T& theT) : t(theT) {}
    friend void f<>(const Friendly<T>&);
    void g() { f(*this); }
};

void h() {
    f(Friendly<int>(1));
}

template<class T> void f(const Friendly<T>& fo) {
    cout << fo.t << endl;
}

int main() {
    h();
    Friendly<int>(2).g();
} ///:~
