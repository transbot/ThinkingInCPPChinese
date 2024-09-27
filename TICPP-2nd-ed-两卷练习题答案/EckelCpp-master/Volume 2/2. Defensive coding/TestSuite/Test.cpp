//: TestSuite:Test.cpp {O}
// 来自《C++编程思想, 第2版》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include "Test.h"
#include <iostream>
#include <typeinfo>
using namespace std;
using namespace TestSuite;

void Test::do_test(bool cond, const std::string& lbl,
  const char* fname, long lineno) {
  if(!cond)
    do_fail(lbl, fname, lineno);
  else
    succeed_();
}

void Test::do_fail(const std::string& lbl,
  const char* fname, long lineno) {
  ++nFail;
  if(osptr) {
    *osptr << typeid(*this).name()
           << "失败:(" << lbl << ") , " << fname
           << " (行" << lineno << ")" << endl;
  }
}

long Test::report() const {
  if(osptr) {
    *osptr << "测试\"" << typeid(*this).name()
           << "\":\n通过: " << nPass
           << "\t 失败: " << nFail
           << endl;
  }
  return nFail;
} ///:~
