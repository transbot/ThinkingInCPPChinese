//: C06:ReplaceStrings.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Replaces strings in-place.
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

bool contains_e(const string& s) {
  return s.find('e') != string::npos;
}

int main() {
  string a[] = {"read", "my", "lips"};
  const size_t SIZE = sizeof a / sizeof a[0];
  replace_if(a, a + SIZE, contains_e, string("kiss"));
  string* p = a;
  while(p != a + SIZE)
    cout << *p++ << endl;
} ///:~
