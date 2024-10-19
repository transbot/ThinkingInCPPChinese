//: C03:Equivalence.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s2("That"), s1("This");
  // The lvalue is a quoted literal
  // and the rvalue is a string:
  if("That" == s2)
    cout << "A match" << endl;
  // The left operand is a string and the right is
  // a pointer to a C-style null terminated string:
  if(s1 != s2.c_str())
    cout << "No match" << endl;
} ///:~
