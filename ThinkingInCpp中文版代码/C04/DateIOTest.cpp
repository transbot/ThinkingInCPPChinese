//: C04:DateIOTest.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} ../C02/Date
#include <iostream>
#include <sstream>
#include "../C02/Date.h"  // Date类在第2章定义
using namespace std;

void testDate(const string& s) {
    istringstream os(s);
    Date d;
    os >> d;
    if (os)
        cout << d << endl;
    else
        cout << "输入错误： \"" << s << "\"" << endl;
}

int main() {
    testDate("08-10-2023");
    testDate("8-10-2023");
    testDate("08 - 10 - 2023");
    testDate("A-10-2023");
    testDate("08%10/2023");
} ///:~
