//: C02:DateTest.cpp
// 自动化测试(通过一个框架)
//{L} Date ../TestSuite/Test
#include <iostream>
#include "DateTest.h"
using namespace std;
int main() {
    DateTest test;
    test.run();
    return test.report();
}
/* 输出:
测试"class DateTest":
通过: 21         失败: 0
*/ ///:~