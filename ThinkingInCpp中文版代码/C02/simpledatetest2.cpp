//: C02:SimpleDateTest2.cpp
//{L} Date
#include <iostream>
#include "Date.h"
using namespace std;

// 测试框架
int nPass = 0, nFail = 0;
void test(bool t) { if(t) ++nPass; else ++nFail; }

int main() {
    // 创建三个Date对象：一个表示作者的生日，一个表示今天，一个表示生日的前一天
    Date mybday(1951, 10, 1);
    Date today;
    Date myevebday("19510930");

    // 测试重载的比较操作符
    test(mybday < today);
    test(mybday <= today);
    test(mybday != today);
    test(mybday == mybday);
    test(mybday >= mybday);
    test(mybday <= mybday);
    test(myevebday < mybday);
    test(mybday > myevebday);
    test(mybday >= myevebday);
    test(mybday != myevebday);
    // 测试getYear()、getMonth()、getDay()和toString()成员函数
    test(mybday.getYear() == 1951);
    test(mybday.getMonth() == 10);
    test(mybday.getDay() == 1);
    test(myevebday.getYear() == 1951);
    test(myevebday.getMonth() == 9);
    test(myevebday.getDay() == 30);
    test(mybday.toString() == "19511001");
    test(myevebday.toString() == "19510930");

    // 测试duration()函数（一个友元），计算两个日期之间的差
    Date d2(2003, 7, 4);
    Date::Duration dur = duration(mybday, d2);
    test(dur.years == 51);
    test(dur.months == 9);
    test(dur.days == 3);
    // 报告结果:
    cout << "通过: " << nPass << ",失败: "
         << nFail << endl;
} ///:~
