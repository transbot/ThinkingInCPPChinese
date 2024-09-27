//: C02:SimpleDateTest.cpp
//{L} Date
#include <iostream>
#include "Date.h" // 来自附录B
using namespace std;

// 测试框架
int nPass = 0, nFail = 0;
void test(bool t) { if(t) nPass++; else nFail++; }
int main() {
    Date mybday(1951, 10, 1);
    test(mybday.getYear() == 1951);
    test(mybday.getMonth() == 10);
    test(mybday.getDay() == 1);
    cout << "通过: " << nPass << ",失败: "
         << nFail << endl;
}
/* 预期的输出：
通过: 3, 失败: 0
*/ ///:~
