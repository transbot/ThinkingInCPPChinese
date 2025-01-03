//: C05:Exercise4.cpp {-xo}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
class Noncomparable {};

struct HardLogic {
  Noncomparable nc1, nc2;
  void compare() {
    return nc1 == nc2; // Compiler error
  }
};

template<class T> struct SoftLogic {
  Noncomparable nc1, nc2;
  void noOp() {}
  void compare() {
    nc1 == nc2;
  }
};

int main() {
  SoftLogic<Noncomparable> l;
  l.noOp();
} ///:~
