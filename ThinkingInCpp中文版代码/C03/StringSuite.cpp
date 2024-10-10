//: C03:StringSuite.cpp
//{L} ../TestSuite/Test ../TestSuite/Suite
//{L} TrimTest
// 这个测试套件用于对第3章的代码进行测试
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
    Suite suite("字符串测试");
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
/* 输出：
s1 = 62345
s2 = 12345
套件 "字符串测试"
====================
测试 "StringStorageTest"：
通过：2 失败：0
测试 "SieveTest"：
通过：50 失败：0
测试 "FindTest"：
通过：9 失败：0
测试 "RparseTest"：
通过：8 失败：0
测试 "TrimTest"：
通过：11 失败：0
测试 "CompStrTest"：
通过：8 失败：0
*/ ///:~
