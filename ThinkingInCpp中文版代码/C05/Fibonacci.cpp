//: C05:Fibonacci.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
using namespace std;

template<int n> struct Fib {
  enum { val = Fib<n-1>::val + Fib<n-2>::val };
};

template<> struct Fib<1> { enum { val = 1 }; };

template<> struct Fib<0> { enum { val = 0 }; };

int main() {
  cout << Fib<5>::val << endl;   // 6
  cout << Fib<20>::val << endl;  // 6765
} ///:~
