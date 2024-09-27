//: C05:Factorial.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Compile-time computation using templates.
#include <iostream>
using namespace std;

template<int n> struct Factorial {
  enum { val = Factorial<n-1>::val * n };
};

template<> struct Factorial<0> {
  enum { val = 1 };
};

int main() {
  cout << Factorial<12>::val << endl; // 479001600
} ///:~
