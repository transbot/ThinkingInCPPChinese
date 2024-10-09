//: C03:ReplaceAll.h
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#ifndef REPLACEALL_H
#define REPLACEALL_H
#include <string>

std::string& replaceAll(std::string& context,
  const std::string& from, const std::string& to);
#endif // REPLACEALL_H ///:~
