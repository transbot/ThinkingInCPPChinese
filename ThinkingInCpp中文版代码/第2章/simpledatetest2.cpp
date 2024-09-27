//: C02:SimpleDateTest2.cpp
//{L} Date
#include <iostream>
#include "Date.h"
using namespace std;

// ���Կ��
int nPass = 0, nFail = 0;
void test(bool t) { if(t) ++nPass; else ++nFail; }

int main() {
    // ��������Date����һ����ʾ���ߵ����գ�һ����ʾ���죬һ����ʾ���յ�ǰһ��
    Date mybday(1951, 10, 1);
    Date today;
    Date myevebday("19510930");

    // �������صıȽϲ�����
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
    // ����getYear()��getMonth()��getDay()��toString()��Ա����
    test(mybday.getYear() == 1951);
    test(mybday.getMonth() == 10);
    test(mybday.getDay() == 1);
    test(myevebday.getYear() == 1951);
    test(myevebday.getMonth() == 9);
    test(myevebday.getDay() == 30);
    test(mybday.toString() == "19511001");
    test(myevebday.toString() == "19510930");

    // ����duration()������һ����Ԫ����������������֮��Ĳ�
    Date d2(2003, 7, 4);
    Date::Duration dur = duration(mybday, d2);
    test(dur.years == 51);
    test(dur.months == 9);
    test(dur.days == 3);
    // ������:
    cout << "ͨ��: " << nPass << ",ʧ��: "
         << nFail << endl;
} ///:~
