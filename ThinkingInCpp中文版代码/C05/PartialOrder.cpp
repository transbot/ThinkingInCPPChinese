//: C05:PartialOrder.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// Reveals ordering of function templates.
#include <iostream>
using namespace std;

template<class T> void f(T) {
  cout << "T" << endl;
}

template<class T> void f(T*) {
  cout << "T*" << endl;
}

template<class T> void f(const T*) {
  cout << "const T*" << endl;
}

int main() {
  f(0);            // T
  int i = 0;
  f(&i);           // T*
  const int j = 0;
  f(&j);           // const T*
} ///:~
