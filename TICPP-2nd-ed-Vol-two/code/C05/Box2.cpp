//: C05:Box2.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Defines non-template operators.
#include <iostream>
using namespace std;

template<class T> class Box {
  T t;
public:
  Box(const T& theT) : t(theT) {}
  friend Box<T> operator+(const Box<T>& b1,
                          const Box<T>& b2) {
    return Box<T>(b1.t + b2.t);
  }
  friend ostream&
  operator<<(ostream& os, const Box<T>& b) {
    return os << '[' << b.t << ']';
  }
};

int main() {
  Box<int> b1(1), b2(2);
  cout << b1 + b2 << endl; // [3]
  cout << b1 + 2 << endl; // [3]
} ///:~
