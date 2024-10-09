//: C03:ReplaceAllTest.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <cassert>
#include <iostream>
#include <string>
#include "ReplaceAll.h"
using namespace std;

int main() {
  string text = "Ҫ�������������Ѱ���Լ���"
                "Ҫ������Ϊʱ��ȥ�������塣";
  replaceAll(text, "Ҫ", "��Ҫ");    
  assert(text == "��Ҫ�������������Ѱ���Լ�����Ҫ������Ϊʱ��ȥ�������塣");
} ///:~
