//: C05:Power.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
using namespace std;

template<int N, int P> struct Power {
  enum { val = N * Power<N, P-1>::val };
};

// 一个部分特化的模板
template<int N> struct Power<N, 0> {
  enum { val = 1 };
};

int main() {
  cout << Power<2, 5>::val << endl;  // 32
} ///:~
