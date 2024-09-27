//: C08:TypeInfo.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Illustrates the typeid operator.
#include <iostream>
#include <typeinfo>
using namespace std;

struct PolyBase { virtual ~PolyBase() {} };
struct PolyDer : PolyBase { PolyDer() {} };
struct NonPolyBase {};
struct NonPolyDer : NonPolyBase { NonPolyDer(int) {} };

int main() {
  // Test polymorphic Types
  const PolyDer pd;
  const PolyBase* ppb = &pd;
  cout << typeid(ppb).name() << endl;
  cout << typeid(*ppb).name() << endl;
  cout << boolalpha << (typeid(*ppb) == typeid(pd))
       << endl;
  cout << (typeid(PolyDer) == typeid(const PolyDer))
       << endl;
  // Test non-polymorphic Types
  const NonPolyDer npd(1);
  const NonPolyBase* nppb = &npd;
  cout << typeid(nppb).name() << endl;
  cout << typeid(*nppb).name() << endl;
  cout << (typeid(*nppb) == typeid(npd)) << endl;
  // Test a built-in type
  int i;
  cout << typeid(i).name() << endl;
} ///:~
