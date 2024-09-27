//: C05:UrandTest.cpp {-bor}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <iostream>
#include "Urand.h"
using namespace std;

int main() {
  Urand<10> u;
  for(int i = 0; i < 20; ++i)
    cout << u() << ' ';
} ///:~
