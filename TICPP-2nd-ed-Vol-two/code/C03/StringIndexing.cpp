//: C03:StringIndexing.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <cassert>
#include <string>
using namespace std;

int main() {
  string s("1234");
  assert(s[1] == '2');
  assert(s.at(1) == '2');
} ///:~
