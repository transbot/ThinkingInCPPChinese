//: C07:SimpleGenerators.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Generic generators, including one that creates pairs.
#include <iostream>
#include <utility>

// A generator that increments its value:
template<typename T> class IncrGen {
  T i;
public:
  IncrGen(T ii) : i(ii) {}
  T operator()() { return i++; }
};

// A generator that produces an STL pair<>:
template<typename T1, typename T2> class PairGen {
  T1 i;
  T2 j;
public:
  PairGen(T1 ii, T2 jj) : i(ii), j(jj) {}
  std::pair<T1,T2> operator()() {
    return std::pair<T1,T2>(i++, j++);
  }
};

namespace std {
// A generic global operator<< for printing any STL pair<>:
template<typename F, typename S> ostream&
operator<<(ostream& os, const pair<F,S>& p) {
  return os << p.first << "\t" << p.second << endl;
}
} ///:~
