//: C11:SynchronizedClass.cpp {-dmc}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
//{L} ZThread
#include "zthread/GuardedClass.h"
using namespace ZThread;

class MyClass {
public:
  void func1() {}
  void func2() {}
};

int main() {
  MyClass a;
  a.func1(); // Not synchronized
  a.func2(); // Not synchronized
  GuardedClass<MyClass> b(new MyClass);
  // Synchronized calls, only one thread at a time allowed:
  b->func1();
  b->func2();
} ///:~
