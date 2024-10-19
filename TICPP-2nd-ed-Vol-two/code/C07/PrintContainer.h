//: C07:PrintContainer.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Prints a sequence container
#ifndef PRINT_CONTAINER_H
#define PRINT_CONTAINER_H
#include "../C06/PrintSequence.h"

template<class Cont>
void print(Cont& c, const char* nm = "",
           const char* sep = "\n",
           std::ostream& os = std::cout) {
  print(c.begin(), c.end(), nm, sep, os);
}
#endif ///:~
