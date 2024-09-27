//: C10:ProxyDemo.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Simple demonstration of the Proxy pattern.
#include <iostream>
using namespace std;

class ProxyBase {
public:
  virtual void f() = 0;
  virtual void g() = 0;
  virtual void h() = 0;
  virtual ~ProxyBase() {}
};

class Implementation : public ProxyBase {
public:
  void f() { cout << "Implementation.f()" << endl; }
  void g() { cout << "Implementation.g()" << endl; }
  void h() { cout << "Implementation.h()" << endl; }
};

class Proxy : public ProxyBase {
  ProxyBase* implementation;
public:
  Proxy() { implementation = new Implementation(); }
  ~Proxy() { delete implementation; }
  // Forward calls to the implementation:
  void f() { implementation->f(); }
  void g() { implementation->g(); }
  void h() { implementation->h(); }
};

int main()  {
  Proxy p;
  p.f();
  p.g();
  p.h();
} ///:~
