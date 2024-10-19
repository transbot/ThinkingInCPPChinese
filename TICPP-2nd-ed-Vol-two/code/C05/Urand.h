//: C05:Urand.h {-bor}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Unique randomizer.
#ifndef URAND_H
#define URAND_H
#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <ctime>
using std::size_t;
using std::bitset;

template<size_t UpperBound> class Urand {
  bitset<UpperBound> used;
public:
  Urand() { srand(time(0)); } // Randomize
  size_t operator()(); // The "generator" function
};

template<size_t UpperBound>
inline size_t Urand<UpperBound>::operator()() {
  if(used.count() == UpperBound)
    used.reset();  // Start over (clear bitset)
  size_t newval;
  while(used[newval = rand() % UpperBound])
    ; // Until unique value is found
  used[newval] = true;
  return newval;
}
#endif // URAND_H ///:~
