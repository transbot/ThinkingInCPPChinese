//: C03:StringIterators.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

int main() {
  string source("�����ַ���");
  string s(source.begin(), source.end());
  assert(s == source);
  cout << s; // Ӧ����������ַ���
} ///:~
