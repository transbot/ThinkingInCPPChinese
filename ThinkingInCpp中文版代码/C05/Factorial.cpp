//: C05:Factorial.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 使用模板在编译时计算阶乘
#include <iostream>
using namespace std;

template<int n> struct Factorial {
  enum { val = Factorial<n-1>::val * n };
};

template<> struct Factorial<0> {
  enum { val = 1 };
};

int main() {
  cout << Factorial<12>::val << endl; // 479001600
} ///:~
