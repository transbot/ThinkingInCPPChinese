//: C05:ArraySize.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <cstddef>
using std::size_t;

template<size_t R, size_t C, typename T>
void init1(T a[R][C]) {
  for(size_t i = 0; i < R; ++i)
    for(size_t j = 0; j < C; ++j)
      a[i][j] = T();
}

template<size_t R, size_t C, class T>
void init2(T (&a)[R][C]) {  // Reference parameter
  for(size_t i = 0; i < R; ++i)
    for(size_t j = 0; j < C; ++j)
      a[i][j] = T();
}

int main() {
  int a[10][20];
  init1<10,20>(a);  // Must specify
  init2(a);         // Sizes deduced
} ///:~
