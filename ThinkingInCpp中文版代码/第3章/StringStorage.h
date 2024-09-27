//: C03:StringStorage.h
// ���ԡ�C++���˼��, ��2�桷
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#ifndef STRINGSTORAGE_H
#define STRINGSTORAGE_H
#include <iostream>
#include <string>
#include "../TestSuite/Test.h"
using std::cout;
using std::endl;
using std::string;

class StringStorageTest : public TestSuite::Test {
public:
  void run() {
    string s1("12345");
    // Ҫô����һ���������ڶ�����
    // Ҫôʹ�����ü�����ģ��һ�ο���������
    string s2 = s1;
    test_(s1 == s2);
    // ������Σ�����䶼ֻ���޸�s1��
    s1[0] = '6';
    cout << "s1 = " << s1 << endl;  // 62345
    cout << "s2 = " << s2 << endl;  // 12345
    test_(s1 != s2);
  }
};
#endif // STRINGSTORAGE_H ///:~
