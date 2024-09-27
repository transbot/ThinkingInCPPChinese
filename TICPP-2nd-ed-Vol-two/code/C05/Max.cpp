//: C05:Max.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <iostream>
using namespace std;

template<int n1, int n2> struct Max {
  enum { val = n1 > n2 ? n1 : n2 };
};

int main() {
  cout << Max<10, 20>::val << endl;  // 20
} ///:~
