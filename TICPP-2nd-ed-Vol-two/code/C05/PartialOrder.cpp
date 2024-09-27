//: C05:PartialOrder.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
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
