//: C05:FailedTransform.cpp {-xo}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s("LOWER");
  transform(s.begin(), s.end(), s.begin(), tolower);
  cout << s << endl;
} ///:~
