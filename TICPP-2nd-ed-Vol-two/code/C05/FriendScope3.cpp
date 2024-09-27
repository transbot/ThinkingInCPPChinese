//: C05:FriendScope3.cpp {-bor}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Microsoft: use the -Za (ANSI-compliant) option
#include <iostream>
using namespace std;

template<class T> class Friendly {
  T t;
public:
  Friendly(const T& theT) : t(theT) {}
  friend void f(const Friendly<T>& fo) {
    cout << fo.t << endl;
  }
  void g() { f(*this); }
};

void h() {
  f(Friendly<int>(1));
}

int main() {
  h();
  Friendly<int>(2).g();
} ///:~
