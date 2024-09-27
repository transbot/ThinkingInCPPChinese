//: C01:BadException.cpp {-bor}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <exception>    // For std::bad_exception
#include <iostream>
#include <cstdio>
using namespace std;

// Exception classes:
class A {};
class B {};

// terminate() handler
void my_thandler() {
  cout << "terminate called" << endl;
  exit(0);
}

// unexpected() handlers
void my_uhandler1() { throw A(); }
void my_uhandler2() { throw; }

// If we embed this throw statement in f or g,
// the compiler detects the violation and reports
// an error, so we put it in its own function.
void t() { throw B(); }

void f() throw(A) { t(); }
void g() throw(A, bad_exception) { t(); }

int main() {
  set_terminate(my_thandler);
  set_unexpected(my_uhandler1);
  try {
    f();
  } catch(A&) {
    cout << "caught an A from f" << endl;
  }
  set_unexpected(my_uhandler2);
  try {
    g();
  } catch(bad_exception&) {
    cout << "caught a bad_exception from g" << endl;
  }
  try {
    f();
  } catch(...) {
    cout << "This will never print" << endl;
  }
} ///:~
