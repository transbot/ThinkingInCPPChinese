//: C06:MergeTest.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Test merging in sorted ranges.
//{L} Generators
#include <algorithm>
#include "PrintSequence.h"
#include "Generators.h"
using namespace std;

int main() {
  const int SZ = 15;
  int a[SZ*2] = {0};
  // Both ranges go in the same array:
  generate(a, a + SZ, SkipGen(0, 2));
  a[3] = 4;
  a[4] = 4;
  generate(a + SZ, a + SZ*2, SkipGen(1, 3));
  print(a, a + SZ, "range1", " ");
  print(a + SZ, a + SZ*2, "range2", " ");
  int b[SZ*2] = {0}; // Initialize all to zero
  merge(a, a + SZ, a + SZ, a + SZ*2, b);
  print(b, b + SZ*2, "merge", " ");
  // Reset b
  for(int i = 0; i < SZ*2; i++)
    b[i] = 0;
  inplace_merge(a, a + SZ, a + SZ*2);
  print(a, a + SZ*2, "inplace_merge", " ");
  int* end = set_union(a, a + SZ, a + SZ, a + SZ*2, b);
  print(b, end, "set_union", " ");
} ///:~
