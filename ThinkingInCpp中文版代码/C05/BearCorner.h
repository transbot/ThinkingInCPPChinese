//: C05:BearCorner.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#ifndef BEARCORNER_H
#define BEARCORNER_H
#include <iostream>
using std::ostream;

// 表示各种物品的类（也就是客人的traits，可以理解成客人的“偏好”或“特征”）：
class Milk {
public:
    friend ostream& operator<<(ostream& os, const Milk&) { return os << "牛奶"; }
};

class CondensedMilk {
public:
    friend ostream& operator<<(ostream& os, const CondensedMilk &) {
        return os << "炼乳";
    }
};

class Honey {
public:
    friend ostream& operator<<(ostream& os, const Honey&) { return os << "蜂蜜"; }
};

class Cookies {
public:
    friend ostream& operator<<(ostream& os, const Cookies&) { return os << "饼干"; }
};

// 表示各种客人的类：
class Bear {
public:
    friend ostream& operator<<(ostream& os, const Bear&) { return os << "泰迪"; }
};

class Boy {
public:
    friend ostream& operator<<(ostream& os, const Boy&) { return os << "帕特里克"; }
};

// 主traits模板（现在是空的，可以容纳通用类型）
template<class Guest> class GuestTraits;

// 针对客人类型的traits特化
// 熊喜欢炼乳和蜂蜜
template<> class GuestTraits<Bear> {
public:
    typedef CondensedMilk beverage_type;
    typedef Honey snack_type;
};

// 男孩喜欢牛奶和饼干
template<> class GuestTraits<Boy> {
public:
    typedef Milk beverage_type;
    typedef Cookies snack_type;
};
#endif // BEARCORNER_H ///:~
