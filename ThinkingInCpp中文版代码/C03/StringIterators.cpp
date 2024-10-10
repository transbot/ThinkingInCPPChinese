//: C03:StringIterators.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

int main() {
  string source("测试字符串");
  string s(source.begin(), source.end());
  assert(s == source);
  cout << s; // 应输出：测试字符串
} ///:~
