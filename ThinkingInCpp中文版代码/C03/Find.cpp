//: C03:Find.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

//{L} ../TestSuite/Test
#include "Find.h"
#include "../TestSuite/Test.h"

int main() {
  FindTest t;
  t.run();
  return t.report();
} ///:~
