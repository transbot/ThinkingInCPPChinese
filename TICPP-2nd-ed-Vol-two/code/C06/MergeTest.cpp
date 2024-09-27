//: C06:MergeTest.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
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
