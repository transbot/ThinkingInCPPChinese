//: C02:DateTest.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Automated testing (with a framework).
//{L} Date ../TestSuite/Test
#include <iostream>
#include "DateTest.h"
using namespace std;

int main() {
  DateTest test;
  test.run();
  return test.report();
}
/* Output:
Test "DateTest":
        Passed: 21,      Failed: 0
*/ ///:~
