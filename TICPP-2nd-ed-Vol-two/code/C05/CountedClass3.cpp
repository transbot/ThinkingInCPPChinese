//: C05:CountedClass3.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <iostream>
using namespace std;

template<class T> class Counted {
  static int count;
public:
  Counted() { ++count; }
  Counted(const Counted<T>&) { ++count; }
  ~Counted() { --count; }
  static int getCount() { return count; }
};

template<class T> int Counted<T>::count = 0;

// Curious class definitions
class CountedClass : public Counted<CountedClass> {};
class CountedClass2 : public Counted<CountedClass2> {};

int main() {
  CountedClass a;
  cout << CountedClass::getCount() << endl;    // 1
  CountedClass b;
  cout << CountedClass::getCount() << endl;    // 2
  CountedClass2 c;
  cout << CountedClass2::getCount() << endl;   // 1 (!)
} ///:~
