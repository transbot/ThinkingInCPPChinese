//: C06:CopyInts.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Copies ints without an explicit loop.
#include <algorithm>
#include <cassert>
#include <cstddef>  // For size_t
using namespace std;

int main() {
  int a[] = { 10, 20, 30 };
  const size_t SIZE = sizeof a / sizeof a[0];
  int b[SIZE];
  copy(a, a + SIZE, b);
  for(size_t i = 0; i < SIZE; ++i)
    assert(a[i] == b[i]);
} ///:~
