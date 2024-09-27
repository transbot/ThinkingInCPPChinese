//: C08:IntermediateCast.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <cassert>
#include <typeinfo>
using namespace std;

class B1 {
public:
  virtual ~B1() {}
};

class B2 {
public:
  virtual ~B2() {}
};

class MI : public B1, public B2 {};
class Mi2 : public MI {};

int main() {
  B2* b2 = new Mi2;
  Mi2* mi2 = dynamic_cast<Mi2*>(b2);
  MI* mi = dynamic_cast<MI*>(b2);
  B1* b1 = dynamic_cast<B1*>(b2);
  assert(typeid(b2) != typeid(Mi2*));
  assert(typeid(b2) == typeid(B2*));
  delete b2;
} ///:~
