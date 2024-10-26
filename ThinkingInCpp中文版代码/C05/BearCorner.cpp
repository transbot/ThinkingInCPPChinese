//: C05:BearCorner.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示如何使用traits类
#include <iostream>
#include "BearCorner.h"
using namespace std;

// 一个自定义的traits类
class MixedUpTraits {
public:
    typedef Milk beverage_type;
    typedef Honey snack_type;
};

// Guest模板（使用一个traits类）
template<class Guest, class traits = GuestTraits<Guest>> class BearCorner {
    Guest theGuest;
    typedef typename traits::beverage_type beverage_type;
    typedef typename traits::snack_type snack_type;
    beverage_type bev; // 喝的
    snack_type snack;  // 吃的
public:
    BearCorner(const Guest& g) : theGuest(g) {}
    void entertain() {
        cout << "向" << theGuest << "提供" << bev << "和" << snack << endl;
    }
};

int main() {
    Boy cr;
    BearCorner<Boy> pc1(cr);
    pc1.entertain();
    Bear pb;
    BearCorner<Bear> pc2(pb);
    pc2.entertain();
    BearCorner<Bear, MixedUpTraits> pc3(pb);
    pc3.entertain();
} ///:~
