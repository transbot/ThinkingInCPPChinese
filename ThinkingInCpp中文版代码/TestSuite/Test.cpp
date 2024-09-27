//: TestSuite:Test.cpp {O}
// ���ԡ�C++���˼��, ��2�桷
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include "Test.h"
#include <iostream>
#include <typeinfo>
using namespace std;
using namespace TestSuite;

void Test::do_test(bool cond, const std::string& lbl,
  const char* fname, long lineno) {
  if(!cond)
    do_fail(lbl, fname, lineno);
  else
    succeed_();
}

void Test::do_fail(const std::string& lbl,
  const char* fname, long lineno) {
  ++nFail;
  if(osptr) {
    *osptr << typeid(*this).name()
           << "ʧ��:(" << lbl << ") , " << fname
           << " (��" << lineno << ")" << endl;
  }
}

long Test::report() const {
  if(osptr) {
    *osptr << "����\"" << typeid(*this).name()
           << "\":\nͨ��: " << nPass
           << "\t ʧ��: " << nFail
           << endl;
  }
  return nFail;
} ///:~
