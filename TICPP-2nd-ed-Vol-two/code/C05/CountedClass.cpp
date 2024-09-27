//: C05:CountedClass.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Object counting via static members.
#include <iostream>
using namespace std;

class CountedClass {
  static int count;
public:
  CountedClass() { ++count; }
  CountedClass(const CountedClass&) { ++count; }
  ~CountedClass() { --count; }
  static int getCount() { return count; }
};

int CountedClass::count = 0;

int main() {
  CountedClass a;
  cout << CountedClass::getCount() << endl;   // 1
  CountedClass b;
  cout << CountedClass::getCount() << endl;   // 2
  { // An arbitrary scope:
    CountedClass c(b);
    cout << CountedClass::getCount() << endl; // 3
    a = c;
    cout << CountedClass::getCount() << endl; // 3
  }
  cout << CountedClass::getCount() << endl;   // 2
} ///:~
