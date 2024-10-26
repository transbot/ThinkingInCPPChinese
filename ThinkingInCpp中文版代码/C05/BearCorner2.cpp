//: C05:BearCorner2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 演示策略类
#include <iostream>
#include "BearCorner.h"
using namespace std;

// 策略类（要求一个静态doAction()函数）：
class Feed {
public:
    static const char* doAction() { return "喂"; }
};

class Stuff {
public:
    static const char* doAction() { return "填充"; }
};

// Guest模板（使用了一个策略和一个traits类）
template<class Guest, class Action, class traits = GuestTraits<Guest> >
class BearCorner {
    Guest theGuest;
    typedef typename traits::beverage_type beverage_type;
    typedef typename traits::snack_type snack_type;
    beverage_type bev; // 喝的
    snack_type snack;  // 吃的 
public:
    BearCorner(const Guest& g) : theGuest(g) {}
    void entertain() {
        cout << "用" << bev << "和" << snack
             << Action::doAction() << theGuest << endl;
    }
};

int main() {
    Boy cr;
    BearCorner<Boy, Feed> pc1(cr);
    pc1.entertain();
    Bear pb;
    BearCorner<Bear, Stuff> pc2(pb);
    pc2.entertain();
} ///:~
