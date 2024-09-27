//: C05:Conditionals.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Uses compile-time conditions to choose code.
#include <iostream>
using namespace std;

template<bool cond> struct Select {};

template<> class Select<true> {
  static void statement1() {
    cout << "This is statement1 executing\n";
  }
public:
  static void f() { statement1(); }
};

template<> class Select<false> {
  static void statement2() {
    cout << "This is statement2 executing\n";
  }
public:
  static void f() { statement2(); }
};

template<bool cond> void execute() {
  Select<cond>::f();
}

int main() {
  execute<sizeof(int) == 4>();
} ///:~
