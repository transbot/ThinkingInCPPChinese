//: C03:StringIndexing.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <cassert>
#include <string>
using namespace std;

int main() {
  string s("1234");
  assert(s[1] == '2');
  assert(s.at(1) == '2');
} ///:~
