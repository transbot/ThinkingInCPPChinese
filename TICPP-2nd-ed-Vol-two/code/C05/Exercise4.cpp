//: C05:Exercise4.cpp {-xo}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
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
