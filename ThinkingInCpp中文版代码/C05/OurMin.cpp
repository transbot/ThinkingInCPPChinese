//: C05:OurMin.cpp {O}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#ifndef OURMIN_CPP
#define OURMIN_CPP
#include "OurMin.h"

// min()的定义
template<typename T> const T& min(const T& a, const T& b) {
  return (a < b) ? a : b;
}
#endif // OURMIN_CPP ///:~
