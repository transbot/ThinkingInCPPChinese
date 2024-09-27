//: C05:Sortable.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Template specialization.
#ifndef SORTABLE_H
#define SORTABLE_H
#include <cstring>
#include <cstddef>
#include <string>
#include <vector>
using std::size_t;

template<class T>
class Sortable : public std::vector<T> {
public:
  void sort();
};

template<class T>
void Sortable<T>::sort() { // A simple sort
  for(size_t i = this->size(); i > 0; --i)
    for(size_t j = 1; j < i; ++j)
      if(this->at(j-1) > this->at(j)) {
        T t = this->at(j-1);
        this->at(j-1) = this->at(j);
        this->at(j) = t;
      }
}

// Partial specialization for pointers:
template<class T>
class Sortable<T*> : public std::vector<T*> {
public:
  void sort();
};

template<class T>
void Sortable<T*>::sort() {
  for(size_t i = this->size(); i > 0; --i)
    for(size_t j = 1; j < i; ++j)
      if(*this->at(j-1) > *this->at(j)) {
        T* t = this->at(j-1);
        this->at(j-1) = this->at(j);
        this->at(j) = t;
      }
}

// Full specialization for char*
// (Made inline here for convenience -- normally you would
// place the function body in a separate file and only
// leave the declaration here).
template<> inline void Sortable<char*>::sort() {
  for(size_t i = this->size(); i > 0; --i)
    for(size_t j = 1; j < i; ++j)
      if(std::strcmp(this->at(j-1), this->at(j)) > 0) {
        char* t = this->at(j-1);
        this->at(j-1) = this->at(j);
        this->at(j) = t;
      }
}
#endif // SORTABLE_H ///:~
