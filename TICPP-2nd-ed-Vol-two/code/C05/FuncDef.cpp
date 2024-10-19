//: C05:FuncDef.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
using namespace std;

template<class T> T sum(T* b, T* e, T init = T()) {
  while(b != e)
    init += *b++;
  return init;
}

int main() {
  int a[] = { 1, 2, 3 };
  cout << sum(a, a + sizeof a / sizeof a[0]) << endl; // 6
} ///:~
