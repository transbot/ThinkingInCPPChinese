//: C05:Unroll.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Unrolls an implicit loop via inlining.
#include <iostream>
using namespace std;

template<int n> inline int power(int m) {
  return power<n-1>(m) * m;
}

template<> inline int power<1>(int m) {
  return m;
}

template<> inline int power<0>(int m) {
  return 1;
}

int main() {
  int m = 4;
  cout << power<3>(m) << endl;
} ///:~
