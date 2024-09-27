//: C05:Fibonacci.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <iostream>
using namespace std;

template<int n> struct Fib {
  enum { val = Fib<n-1>::val + Fib<n-2>::val };
};

template<> struct Fib<1> { enum { val = 1 }; };

template<> struct Fib<0> { enum { val = 0 }; };

int main() {
  cout << Fib<5>::val << endl;   // 6
  cout << Fib<20>::val << endl;  // 6765
} ///:~
