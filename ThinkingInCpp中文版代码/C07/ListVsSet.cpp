//: C07:ListVsSet.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 比较list和set的性能
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include "PrintContainer.h"
using namespace std;

class Obj {
    int a[20]; // 为了占用额外空间
    int val;

public:
    Obj() : val(rand() % 500) {}
    friend bool operator<(const Obj& a, const Obj& b) {
        return a.val < b.val;
    }
    friend bool operator==(const Obj& a, const Obj& b) {
        return a.val == b.val;
    }
    friend ostream& operator<<(ostream& os, const Obj& a) {
        return os << a.val;
    }
};

struct ObjGen {
    Obj operator()() { return Obj(); }
};

int main() {
    const int SZ = 5000;
    srand(time(0));
    list<Obj> lo;

    clock_t ticks = clock();
    generate_n(back_inserter(lo), SZ, ObjGen());
    lo.sort();
    lo.unique();
    cout << "list: " << clock() - ticks << endl;

    set<Obj> so;
    ticks = clock();
    generate_n(inserter(so, so.begin()), SZ, ObjGen());
    cout << "set: " << clock() - ticks << endl;

    print(lo);
    print(so);
} ///:~
