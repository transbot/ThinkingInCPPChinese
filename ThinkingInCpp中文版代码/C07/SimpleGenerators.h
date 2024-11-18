//: C07:SimpleGenerators.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 泛型生成器，其中有一个可以生成pair
#include <iostream>
#include <utility>

// 该生成器递增自己的值
template<typename T>
class IncrGen {
    T i;
public:
    IncrGen(T ii) : i(ii) {}
    T operator()() { return i++; }
};

// 该生成器生成一个 STL pair<>
template<typename T1, typename T2>
class PairGen {
    T1 i;
    T2 j;
public:
    PairGen(T1 ii, T2 jj) : i(ii), j(jj) {}
    std::pair<T1,T2> operator()() {
        return std::pair<T1,T2>(i++, j++);
    }
};

namespace std {
    // 泛型全局operator<<，用于打印任何 STL pair<>
    template<typename F, typename S>
    ostream& operator<<(ostream& os, const pair<F,S>& p) {
        return os << p.first << "\t" << p.second << endl;
    }
} ///:~
