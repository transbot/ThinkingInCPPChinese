//: C07:SimpleGenerators.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
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
