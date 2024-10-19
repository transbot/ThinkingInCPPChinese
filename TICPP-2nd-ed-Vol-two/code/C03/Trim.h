//: C03:Trim.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// General tool to strip spaces from both ends.
#ifndef TRIM_H
#define TRIM_H
#include <string>
#include <cstddef>

inline std::string trim(const std::string& s) {
  if(s.length() == 0)
    return s;
  std::size_t beg = s.find_first_not_of(" \a\b\f\n\r\t\v");
  std::size_t end = s.find_last_not_of(" \a\b\f\n\r\t\v");
  if(beg == std::string::npos) // No non-spaces
    return "";
  return std::string(s, beg, end - beg + 1);
}
#endif // TRIM_H ///:~
