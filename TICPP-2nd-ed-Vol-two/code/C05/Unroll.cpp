//: C05:Unroll.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Unrolls an implicit loop via inlining.
#include <iostream>
using namespace std;

template<int n> inline int power(int m) {
  return power<n-1>(m) * m;
}

template<> inline int power<1>(int m) {
  return m;
}

template<> inline int power<0>(int m) {
  return 1;
}

int main() {
  int m = 4;
  cout << power<3>(m) << endl;
} ///:~
