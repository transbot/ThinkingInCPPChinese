//: C05:MyVector.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Optimizes away temporaries via templates.
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// A proxy class for sums of vectors
template<class, size_t> class MyVectorSum;

template<class T, size_t N> class MyVector {
  T data[N];
public:
  MyVector<T,N>& operator=(const MyVector<T,N>& right) {
    for(size_t i = 0; i < N; ++i)
      data[i] = right.data[i];
    return *this;
  }
  MyVector<T,N>& operator=(const MyVectorSum<T,N>& right);
  const T& operator[](size_t i) const { return data[i]; }
  T& operator[](size_t i) { return data[i]; }
};

// Proxy class hold references; uses lazy addition
template<class T, size_t N> class MyVectorSum {
  const MyVector<T,N>& left;
  const MyVector<T,N>& right;
public:
  MyVectorSum(const MyVector<T,N>& lhs,
              const MyVector<T,N>& rhs)
  : left(lhs), right(rhs) {}
  T operator[](size_t i) const {
    return left[i] + right[i];
  }
};

// Operator to support v3 = v1 + v2
template<class T, size_t N> MyVector<T,N>&
MyVector<T,N>::operator=(const MyVectorSum<T,N>& right) {
  for(size_t i = 0; i < N; ++i)
    data[i] = right[i];
  return *this;
}

// operator+ just stores references
template<class T, size_t N> inline MyVectorSum<T,N>
operator+(const MyVector<T,N>& left,
          const MyVector<T,N>& right) {
  return MyVectorSum<T,N>(left, right);
}

// Convenience functions for the test program below
template<class T, size_t N> void init(MyVector<T,N>& v) {
  for(size_t i = 0; i < N; ++i)
    v[i] = rand() % 100;
}

template<class T, size_t N> void print(MyVector<T,N>& v) {
  for(size_t i = 0; i < N; ++i)
    cout << v[i] << ' ';
  cout << endl;
}

int main() {
  srand(time(0));
  MyVector<int, 5> v1;
  init(v1);
  print(v1);
  MyVector<int, 5> v2;
  init(v2);
  print(v2);
  MyVector<int, 5> v3;
  v3 = v1 + v2;
  print(v3);
  MyVector<int, 5> v4;
  // Not yet supported:
//!  v4 = v1 + v2 + v3;
} ///:~
