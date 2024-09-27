//: C05:Power.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <iostream>
using namespace std;

template<int N, int P> struct Power {
  enum { val = N * Power<N, P-1>::val };
};

template<int N> struct Power<N, 0> {
  enum { val = 1 };
};

int main() {
  cout << Power<2, 5>::val << endl;  // 32
} ///:~
