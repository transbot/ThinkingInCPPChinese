//: C10:ProxyDemo.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
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
