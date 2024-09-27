//: C03:StringSuite.cpp
//{L} ../TestSuite/Test ../TestSuite/Suite
//{L} TrimTest
// ��������׼����ڶԵ�3�µĴ�����в���
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
    Suite suite("�ַ�������");
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
/* �����
s1 = 62345
s2 = 12345
�׼� "�ַ�������"
====================
���� "StringStorageTest"��
ͨ����2 ʧ�ܣ�0
���� "SieveTest"��
ͨ����50 ʧ�ܣ�0
���� "FindTest"��
ͨ����9 ʧ�ܣ�0
���� "RparseTest"��
ͨ����8 ʧ�ܣ�0
���� "TrimTest"��
ͨ����11 ʧ�ܣ�0
���� "CompStrTest"��
ͨ����8 ʧ�ܣ�0
*/ ///:~
