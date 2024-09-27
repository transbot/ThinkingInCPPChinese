//: C01:Autoexcp.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// No matching conversions.
#include <iostream>
using namespace std;

class Except1 {};

class Except2 {
public:
  Except2(const Except1&) {}
};

void f() { throw Except1(); }

int main() {
  try { f();
  } catch(Except2&) {
    cout << "inside catch(Except2)" << endl;
  } catch(Except1&) {
    cout << "inside catch(Except1)" << endl;
  }
} ///:~
