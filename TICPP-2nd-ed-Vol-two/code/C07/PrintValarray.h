//: C07:PrintValarray.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
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
