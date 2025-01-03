//: C02:SimpleDateTest.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} Date
#include <iostream>
#include "Date.h" // From Appendix B
using namespace std;

// Test machinery
int nPass = 0, nFail = 0;
void test(bool t) { if(t) nPass++; else nFail++; }

int main() {
  Date mybday(1951, 10, 1);
  test(mybday.getYear() == 1951);
  test(mybday.getMonth() == 10);
  test(mybday.getDay() == 1);
  cout << "Passed: " << nPass << ", Failed: "
       << nFail << endl;
}
/* Expected output:
Passed: 3, Failed: 0
*/ ///:~
