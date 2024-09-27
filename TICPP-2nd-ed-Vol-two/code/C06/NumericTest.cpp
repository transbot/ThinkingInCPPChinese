//: C06:NumericTest.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>
#include <numeric>
#include "PrintSequence.h"
using namespace std;

int main() {
  int a[] = { 1, 1, 2, 2, 3, 5, 7, 9, 11, 13 };
  const int ASZ = sizeof a / sizeof a[0];
  print(a, a + ASZ, "a", " ");
  int r = accumulate(a, a + ASZ, 0);
  cout << "accumulate 1: " << r << endl;
  // Should produce the same result:
  r = accumulate(a, a + ASZ, 0, plus<int>());
  cout << "accumulate 2: " << r << endl;
  int b[] = { 1, 2, 3, 4, 1, 2, 3, 4, 1, 2 };
  print(b, b + sizeof b / sizeof b[0], "b", " ");
  r = inner_product(a, a + ASZ, b, 0);
  cout << "inner_product 1: " << r << endl;
  // Should produce the same result:
  r = inner_product(a, a + ASZ, b, 0,
    plus<int>(), multiplies<int>());
  cout << "inner_product 2: " << r << endl;
  int* it = partial_sum(a, a + ASZ, b);
  print(b, it, "partial_sum 1", " ");
  // Should produce the same result:
  it = partial_sum(a, a + ASZ, b, plus<int>());
  print(b, it, "partial_sum 2", " ");
  it = adjacent_difference(a, a + ASZ, b);
  print(b, it, "adjacent_difference 1"," ");
  // Should produce the same result:
  it = adjacent_difference(a, a + ASZ, b, minus<int>());
  print(b, it, "adjacent_difference 2"," ");
} ///:~
