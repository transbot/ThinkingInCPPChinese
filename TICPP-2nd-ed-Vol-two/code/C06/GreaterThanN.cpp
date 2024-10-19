//: C06:GreaterThanN.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
using namespace std;

class gt_n {
  int value;
public:
  gt_n(int val) : value(val) {}
  bool operator()(int n) { return n > value; }
};

int main() {
  gt_n f(4);
  cout << f(3) << endl;  // Prints 0 (for false)
  cout << f(5) << endl;  // Prints 1 (for true)
} ///:~
