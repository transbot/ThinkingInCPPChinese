//: C05:StrTolower.cpp {O} {-mwcc}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

string strTolower(string s) {
  transform(s.begin(), s.end(), s.begin(), tolower);
  return s;
} ///:~
