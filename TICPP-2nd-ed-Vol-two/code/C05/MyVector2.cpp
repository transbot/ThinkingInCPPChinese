//: C05:MyVector2.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Handles sums of any length with expression templates.
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// A proxy class for sums of vectors
template<class, size_t, class, class> class MyVectorSum;

template<class T, size_t N> class MyVector {
  T data[N];
public:
  MyVector<T,N>& operator=(const MyVector<T,N>& right) {
    for(size_t i = 0; i < N; ++i)
      data[i] = right.data[i];
    return *this;
  }
  template<class Left, class Right> MyVector<T,N>&
  operator=(const MyVectorSum<T,N,Left,Right>& right);
  const T& operator[](size_t i) const {
    return data[i];
  }
  T& operator[](size_t i) {
    return data[i];
  }
};

// Allows mixing MyVector and MyVectorSum
template<class T, size_t N, class Left, class Right>
class MyVectorSum {
  const Left& left;
  const Right& right;
public:
  MyVectorSum(const Left& lhs, const Right& rhs)
  : left(lhs), right(rhs) {}
  T operator[](size_t i) const {
    return left[i] + right[i];
  }
};

template<class T, size_t N>
template<class Left, class Right>
MyVector<T,N>&
MyVector<T,N>::
operator=(const MyVectorSum<T,N,Left,Right>& right) {
  for(size_t i = 0; i < N; ++i)
    data[i] = right[i];
  return *this;
}
// operator+ just stores references
template<class T, size_t N>
inline MyVectorSum<T,N,MyVector<T,N>,MyVector<T,N> >
operator+(const MyVector<T,N>& left,
          const MyVector<T,N>& right) {
  return MyVectorSum<T,N,MyVector<T,N>,MyVector<T,N> >
      (left,right);
}

template<class T, size_t N, class Left, class Right>
inline MyVectorSum<T, N, MyVectorSum<T,N,Left,Right>,
            MyVector<T,N> >
operator+(const MyVectorSum<T,N,Left,Right>& left,
          const MyVector<T,N>& right) {
  return MyVectorSum<T,N,MyVectorSum<T,N,Left,Right>,
                         MyVector<T,N> >
    (left, right);
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
  // Now supported:
  MyVector<int, 5> v4;
  v4 = v1 + v2 + v3;
  print(v4);
  MyVector<int, 5> v5;
  v5 = v1 + v2 + v3 + v4;
  print(v5);
} ///:~
