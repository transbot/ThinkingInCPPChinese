//: C03:StringSuite.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
//{L} ../TestSuite/Test ../TestSuite/Suite
//{L} TrimTest
// Illustrates a test suite for code from Chapter 3
#include <iostream>
#include "../TestSuite/Suite.h"
#include "StringStorage.h"
#include "Sieve.h"
#include "Find.h"
#include "Rparse.h"
#include "TrimTest.h"
#include "CompStr.h"
using namespace std;
using namespace TestSuite;

int main() {
    Suite suite("String Tests");
    suite.addTest(new StringStorageTest);
    suite.addTest(new SieveTest);
    suite.addTest(new FindTest);
    suite.addTest(new RparseTest);
    suite.addTest(new TrimTest);
    suite.addTest(new CompStrTest);
    suite.run();
    long nFail = suite.report();
    suite.free();
    return nFail;
}
/* Output:
s1 = 62345
s2 = 12345
Suite "String Tests"
====================
Test "StringStorageTest":
   Passed: 2   Failed: 0
Test "SieveTest":
   Passed: 50  Failed: 0
Test "FindTest":
   Passed: 9   Failed: 0
Test "RparseTest":
   Passed: 8   Failed: 0
Test "TrimTest":
   Passed: 11  Failed: 0
Test "CompStrTest":
   Passed: 8   Failed: 0
*/ ///:~
