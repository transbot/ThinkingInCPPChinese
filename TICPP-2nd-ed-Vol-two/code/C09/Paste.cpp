//: C09:Paste.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
//{L} Vendor
// Fixing a mess with MI.
#include <iostream>
#include "Vendor.h"
using namespace std;

class MyBase { // Repair Vendor interface
public:
  virtual void v() const = 0;
  virtual void f() const = 0;
  // New interface function:
  virtual void g() const = 0;
  virtual ~MyBase() { cout << "~MyBase()" << endl; }
};

class Paste1 : public MyBase, public Vendor1 {
public:
  void v() const {
    cout << "Paste1::v()" << endl;
    Vendor1::v();
  }
  void f() const {
    cout << "Paste1::f()" << endl;
    Vendor1::f();
  }
  void g() const { cout << "Paste1::g()" << endl; }
  ~Paste1() { cout << "~Paste1()" << endl; }
};

int main() {
  Paste1& p1p = *new Paste1;
  MyBase& mp = p1p; // Upcast
  cout << "calling f()" << endl;
  mp.f();  // Right behavior
  cout << "calling g()" << endl;
  mp.g(); // New behavior
  cout << "calling A(p1p)" << endl;
  A(p1p); // Same old behavior
  cout << "calling B(p1p)" << endl;
  B(p1p);  // Same old behavior
  cout << "delete mp" << endl;
  // Deleting a reference to a heap object:
  delete &mp; // Right behavior
} ///:~
