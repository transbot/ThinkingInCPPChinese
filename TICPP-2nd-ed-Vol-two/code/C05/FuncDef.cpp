//: C05:FuncDef.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <iostream>
using namespace std;

template<class T> T sum(T* b, T* e, T init = T()) {
  while(b != e)
    init += *b++;
  return init;
}

int main() {
  int a[] = { 1, 2, 3 };
  cout << sum(a, a + sizeof a / sizeof a[0]) << endl; // 6
} ///:~
