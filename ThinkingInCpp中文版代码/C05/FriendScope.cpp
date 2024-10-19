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
  friend void f(const Friendly&); // Needs global def.
  void g() { f(*this); }
};

void h() {
  f(Friendly(1));  // Uses ADL
}

void f(const Friendly& fo) {  // Definition of friend
  cout << fo.i << endl;
}

int main() {
  h(); // Prints 1
  Friendly(2).g(); // Prints 2
} ///:~
