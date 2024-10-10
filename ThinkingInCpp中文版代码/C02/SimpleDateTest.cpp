//: C02:SimpleDateTest.cpp
//{L} Date
#include <iostream>
#include "Date.h" // ���Ը�¼B
using namespace std;

// ���Կ��
int nPass = 0, nFail = 0;
void test(bool t) { if(t) nPass++; else nFail++; }
int main() {
    Date mybday(1951, 10, 1);
    test(mybday.getYear() == 1951);
    test(mybday.getMonth() == 10);
    test(mybday.getDay() == 1);
    cout << "ͨ��: " << nPass << ",ʧ��: "
         << nFail << endl;
}
/* Ԥ�ڵ������
ͨ��: 3, ʧ��: 0
*/ ///:~
