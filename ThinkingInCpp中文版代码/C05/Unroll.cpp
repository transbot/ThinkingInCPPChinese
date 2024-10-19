//: C05:Unroll.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Unrolls an implicit loop via inlining.
#include <iostream>
using namespace std;

template<int n> inline int power(int m) {
  return power<n-1>(m) * m;
}

template<> inline int power<1>(int m) {
  return m;
}

template<> inline int power<0>(int m) {
  return 1;
}

int main() {
  int m = 4;
  cout << power<3>(m) << endl;
} ///:~
