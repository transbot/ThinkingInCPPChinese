//: C10:FibonacciGeneratorTest.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
#include "FibonacciGenerator.h"
using namespace std;

int main() {
  FibonacciGenerator f;
  for(int i =0; i < 20; i++)
    cout << f.count() << ": " << f() << endl;
} ///:~
