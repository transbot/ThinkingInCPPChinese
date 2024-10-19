//: C07:PrintValarray.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#ifndef PRINTVALARRAY_H
#define PRINTVALARRAY_H
#include <valarray>
#include <iostream>
#include <cstddef>

template<class T>
void print(const char* lbl, const std::valarray<T>& a) {
  std::cout << lbl << ": ";
  for(std::size_t i = 0; i < a.size(); ++i)
    std::cout << a[i] << ' ';
  std::cout << std::endl;
}
#endif // PRINTVALARRAY_H ///:~
