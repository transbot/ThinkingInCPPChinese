//: C06:PrintSequence.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Prints the contents of any sequence.
#ifndef PRINTSEQUENCE_H
#define PRINTSEQUENCE_H
#include <algorithm>
#include <iostream>
#include <iterator>

template<typename Iter>
void print(Iter first, Iter last, const char* nm = "",
           const char* sep = "\n",
           std::ostream& os = std::cout) {
  if(nm != 0 && *nm != '\0')
    os << nm << ": " << sep;
  typedef typename 
    std::iterator_traits<Iter>::value_type T;
  std::copy(first, last, 
            std::ostream_iterator<T>(std::cout, sep));
  os << std::endl;
}
#endif // PRINTSEQUENCE_H ///:~
