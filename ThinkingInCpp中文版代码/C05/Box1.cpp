//: C05:Box1.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 定义模板操作符
#include <iostream>
using namespace std;

// 前置声明
template<class T> class Box;
template<class T> Box<T> operator+(const Box<T>&, const Box<T>&);
template<class T> ostream& operator<<(ostream&, const Box<T>&);

template<class T>
class Box {
    T t;
public:
    Box(const T& theT) : t(theT) {}
    friend Box operator+<>(const Box<T>&, const Box<T>&);
    friend ostream& operator<< <>(ostream&, const Box<T>&);
};

template<class T>
Box<T> operator+(const Box<T>& b1, const Box<T>& b2) {
    return Box<T>(b1.t + b2.t);
}

template<class T>
ostream& operator<<(ostream& os, const Box<T>& b) {
    return os << '[' << b.t << ']';
}

int main() {
    Box<int> b1(1), b2(2);
    cout << b1 + b2 << endl;   // [3]
    // cout << b1 + 2 << endl; // 没有隐式转换！
} ///:~
