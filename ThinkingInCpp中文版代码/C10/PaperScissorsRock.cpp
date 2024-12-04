//: C10:PaperScissorsRock.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 用“石头-剪子-布”游戏来演示多重调度
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "../purge.h"
using namespace std;

class Paper;
class Scissors;
class Rock;

// 定义游戏结果枚举类型
enum Outcome { WIN, LOSE, DRAW };

// 重载流插入操作符，用于输出游戏结果
ostream& operator<<(ostream& os, const Outcome out) {
    switch(out) {
        default:
        case WIN: return os << "赢了";
        case LOSE: return os << "输了";
        case DRAW: return os << "平局";
    }
}

// 基类Item表示游戏中的一个物品（其实是一种手势）
class Item {
public:
    // 纯虚函数，用于比较两个物品
    virtual Outcome compete(const Item*) = 0;
    // 纯虚函数，用于求值与其他物品的关系
    virtual Outcome eval(const Paper*) const = 0;
    virtual Outcome eval(const Scissors*) const = 0;
    virtual Outcome eval(const Rock*) const = 0;
    // 纯虚函数，用于输出物品名称
    virtual ostream& print(ostream& os) const = 0;
    // 虚析构函数
    virtual ~Item() {}
    // 友元函数，用于输出物品
    friend ostream& operator<<(ostream& os, const Item* it) {
        return it->print(os);
    }
};

// 派生类Paper，表示“布”
class Paper : public Item {
public:
    // 比较两个物品
    Outcome compete(const Item* it) { return it->eval(this);}
    // 求值与其他物品的关系
    Outcome eval(const Paper*) const { return DRAW; }
    Outcome eval(const Scissors*) const { return WIN; }
    Outcome eval(const Rock*) const { return LOSE; }
    // 输出物品名称
    ostream& print(ostream& os) const {
        return os << "布";
    }
};

// 派生类Scissors，表示“剪子”
class Scissors : public Item {
public:
    // 比较两个物品
    Outcome compete(const Item* it) { return it->eval(this);}
    // 求值与其他物品的关系
    Outcome eval(const Paper*) const { return LOSE; }
    Outcome eval(const Scissors*) const { return DRAW; }
    Outcome eval(const Rock*) const { return WIN; }
    // 输出物品名称
    ostream& print(ostream& os) const {
        return os << "剪子";
    }
};

// 派生类Rock，表示“石头”
class Rock : public Item {
public:
    // 比较两个物品
    Outcome compete(const Item* it) { return it->eval(this);}
    // 求值与其他物品的关系
    Outcome eval(const Paper*) const { return WIN; }
    Outcome eval(const Scissors*) const { return LOSE; }
    Outcome eval(const Rock*) const { return DRAW; }
    // 输出物品名称
    ostream& print(ostream& os) const {
        return os << "石头";
    }
};

// 结构体ItemGen用于随机生成物品
struct ItemGen {
    Item* operator()() {
        switch(rand() % 3) {
            default:
            case 0: return new Scissors;
            case 1: return new Paper;
            case 2: return new Rock;
        }
    }
};

// 结构体Compete用于比较两个物品
struct Compete {
    Outcome operator()(Item* a, Item* b) {
        cout << a << "\t" << b << "\t";
        return a->compete(b); // 开始双重调度
    }
};

int main() {
    srand(time(0)); // 初始化随机数生成器
    const int sz = 20;
    vector<Item*> v(sz*2);
    generate(v.begin(), v.end(), ItemGen()); // 生成随机物品（手势）
    transform(v.begin(), v.begin() + sz,
              v.begin() + sz,
              ostream_iterator<Outcome>(cout, "\n"),
              Compete()); // 比较物品（手势）并输出结果
    purge(v); // 清理内存
} ///:~
