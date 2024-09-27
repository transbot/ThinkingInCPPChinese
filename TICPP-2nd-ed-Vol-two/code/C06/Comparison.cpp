//: C06:Comparison.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// The STL range comparison algorithms.
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include "PrintSequence.h"
using namespace std;

int main() {
  // Strings provide a convenient way to create
  // ranges of characters, but you should
  // normally look for native string operations:
  string s1("This is a test");
  string s2("This is a Test");
  cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
  cout << "compare s1 & s1: "
       << equal(s1.begin(), s1.end(), s1.begin()) << endl;
  cout << "compare s1 & s2: "
       << equal(s1.begin(), s1.end(), s2.begin()) << endl;
  cout << "lexicographical_compare s1 & s1: "
       << lexicographical_compare(s1.begin(), s1.end(),
          s1.begin(), s1.end()) <<  endl;
  cout << "lexicographical_compare s1 & s2: "
       << lexicographical_compare(s1.begin(), s1.end(),
          s2.begin(), s2.end()) << endl;
  cout << "lexicographical_compare s2 & s1: "
       << lexicographical_compare(s2.begin(), s2.end(),
          s1.begin(), s1.end()) << endl;
  cout << "lexicographical_compare shortened "
          "s1 & full-length s2: " << endl;
  string s3(s1);
  while(s3.length() != 0) {
    bool result = lexicographical_compare(
      s3.begin(), s3.end(), s2.begin(),s2.end());
    cout << s3 << endl << s2 << ", result = "
         << result << endl;
    if(result == true) break;
    s3 = s3.substr(0, s3.length() - 1);
  }
  pair<string::iterator, string::iterator> p =
    mismatch(s1.begin(), s1.end(), s2.begin());
  print(p.first, s1.end(), "p.first", "");
  print(p.second, s2.end(), "p.second","");
} ///:~
