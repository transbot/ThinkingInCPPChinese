//: C05:Max.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
using namespace std;

template<int n1, int n2> struct Max {
  enum { val = n1 > n2 ? n1 : n2 };
};

int main() {
  cout << Max<10, 20>::val << endl;  // 20
} ///:~
