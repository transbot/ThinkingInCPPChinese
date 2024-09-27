//: C06:CopyInts3.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Uses an output stream iterator.
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
using namespace std;

bool gt15(int x) { return 15 < x; }

int main() {
  int a[] = { 10, 20, 30 };
  const size_t SIZE = sizeof a / sizeof a[0];
  remove_copy_if(a, a + SIZE,
                 ostream_iterator<int>(cout, "\n"), gt15);
} ///:~
