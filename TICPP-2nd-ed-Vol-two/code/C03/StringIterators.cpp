//: C03:StringIterators.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

int main() {
  string source("xxx");
  string s(source.begin(), source.end());
  assert(s == source);
} ///:~
