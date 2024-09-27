//: C05:ToLower2.cpp {-mwcc}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

template<class charT> charT strTolower(charT c) {
  return tolower(c);  // One-arg version called
}

int main() {
  string s("LOWER");
  transform(s.begin(),s.end(),s.begin(),&strTolower<char>);
  cout << s << endl;
} ///:~
