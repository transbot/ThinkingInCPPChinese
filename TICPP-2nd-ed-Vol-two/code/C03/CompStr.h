//: C03:CompStr.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#ifndef COMPSTR_H
#define COMPSTR_H
#include <string>
#include "../TestSuite/Test.h"
using std::string;

class CompStrTest : public TestSuite::Test {
public:
  void run() {
    // Strings to compare
    string s1("This");
    string s2("That");
    test_(s1 == s1);
    test_(s1 != s2);
    test_(s1 > s2);
    test_(s1 >= s2);
    test_(s1 >= s1);
    test_(s2 < s1);
    test_(s2 <= s1);
    test_(s1 <= s1);
  }
};
#endif // COMPSTR_H ///:~
