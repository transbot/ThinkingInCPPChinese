//: C05:NobloatTest.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <iostream>
#include <string>
#include "Nobloat.h"
using namespace std;

template<class StackType>
void emptyTheStack(StackType& stk) {
  while(stk.size() > 0) {
    cout << stk.top() << endl;
    stk.pop();
  }
}

// An overload for emptyTheStack (not a specialization!)
template<class T>
void emptyTheStack(Stack<T*>& stk) {
  while(stk.size() > 0) {
    cout << *stk.top() << endl;
    stk.pop();
  }
}

int main() {
  Stack<int> s1;
  s1.push(1);
  s1.push(2);
  emptyTheStack(s1);
  Stack<int *> s2;
  int i = 3;
  int j = 4;
  s2.push(&i);
  s2.push(&j);
  emptyTheStack(s2);
} ///:~
