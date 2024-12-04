//: C11:SynchronizedClass.cpp {-dmc}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
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
