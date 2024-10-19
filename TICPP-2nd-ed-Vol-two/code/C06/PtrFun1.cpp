//: C06:PtrFun1.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Using ptr_fun() with a unary function.
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int d[] = { 123, 94, 10, 314, 315 };
const int DSZ = sizeof d / sizeof *d;

bool isEven(int x) { return x % 2 == 0; }

int main() {
  vector<bool> vb;
  transform(d, d + DSZ, back_inserter(vb),
    not1(ptr_fun(isEven)));
  copy(vb.begin(), vb.end(),
    ostream_iterator<bool>(cout, " "));
  cout << endl;
  // Output: 1 0 0 0 1
} ///:~
