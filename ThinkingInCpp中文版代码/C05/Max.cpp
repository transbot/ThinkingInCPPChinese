//: C05:Max.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
using namespace std;

template<int n1, int n2> struct Max {
  enum { val = n1 > n2 ? n1 : n2 };
};

int main() {
  cout << Max<10, 20>::val << endl;  // 20
} ///:~
