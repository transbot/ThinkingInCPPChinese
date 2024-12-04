//: C10:PaperScissorsRock_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 用“石头-剪子-布”游戏来演示多重调度，本例是“双重调度”，或者“双分派”
/* 本例使用现代C++进行了改进：
智能指针：
    使用 std::unique_ptr来管理动态分配的内存，避免内存泄漏。
    std::make_unique用于创建std::unique_ptr对象。

现代C++特性：
    使用enum class来定义枚举类型，避免命名空间污染。
    使用override关键字来明确指出重写的虚函数。

随机数生成：
    使用static_cast<unsigned>来确保time(0)的返回值是无符号整数。

自动清理内存：
    使用std::unique_ptr自动管理内存，不需要手动清理内存（不需要原书一直在使用的purge.h了）。
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <memory>
#include <random>
using namespace std;

class Paper;
class Scissors;
class Rock;

// 定义游戏结果枚举类型
enum class Outcome { WIN, LOSE, DRAW };

// 重载流插入操作符，用于输出游戏结果
ostream& operator<<(ostream& os, const Outcome out) {
    switch(out) {
        default:
        case Outcome::WIN: return os << "赢了";
        case Outcome::LOSE: return os << "输了";
        case Outcome::DRAW: return os << "平局";
    }
}

// 基类Item表示游戏中的一个物品（其实是一种手势）
class Item {
public:
    // 纯虚函数，用于比较两个物品
    virtual Outcome compete(const Item*) const = 0;
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
    Outcome compete(const Item* it) const override { return it->eval(this);}
    // 求值与其他物品的关系
    Outcome eval(const Paper*) const override { return Outcome::DRAW; }
    Outcome eval(const Scissors*) const override { return Outcome::WIN; }
    Outcome eval(const Rock*) const override { return Outcome::LOSE; }
    // 输出物品名称
    ostream& print(ostream& os) const override {
        return os << "布";
    }
};

// 派生类Scissors，表示“剪子”
class Scissors : public Item {
public:
    // 比较两个物品
    Outcome compete(const Item* it) const override { return it->eval(this);}
    // 求值与其他物品的关系
    Outcome eval(const Paper*) const override { return Outcome::LOSE; }
    Outcome eval(const Scissors*) const override { return Outcome::DRAW; }
    Outcome eval(const Rock*) const override { return Outcome::WIN; }
    // 输出物品名称
    ostream& print(ostream& os) const override {
        return os << "剪子";
    }
};

// 派生类Rock，表示“石头”
class Rock : public Item {
public:
    // 比较两个物品
    Outcome compete(const Item* it) const override { return it->eval(this);}
    // 求值与其他物品的关系
    Outcome eval(const Paper*) const override { return Outcome::WIN; }
    Outcome eval(const Scissors*) const override { return Outcome::LOSE; }
    Outcome eval(const Rock*) const override { return Outcome::DRAW; }
    // 输出物品名称
    ostream& print(ostream& os) const override {
        return os << "石头";
    }
};

// 结构体ItemGen用于随机生成物品
struct ItemGen {
    std::unique_ptr<Item> operator()() {
        switch(rand() % 3) {
            default:
            case 0: return std::make_unique<Scissors>();
            case 1: return std::make_unique<Paper>();
            case 2: return std::make_unique<Rock>();
        }
    }
};

// 结构体Compete用于比较两个物品
struct Compete {
    Outcome operator()(const std::unique_ptr<Item>& a, const std::unique_ptr<Item>& b) {
        cout << a.get() << "\t" << b.get() << "\t";
        return a->compete(b.get()); // 开始双重调度
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); // 初始化随机数生成器
    const int sz = 20;
    vector<std::unique_ptr<Item>> v(sz * 2);
    generate(v.begin(), v.end(), ItemGen()); // 生成随机物品（手势）
    transform(v.begin(), v.begin() + sz,
              v.begin() + sz,
              ostream_iterator<Outcome>(cout, "\n"),
              Compete()); // 比较物品（手势）并输出结果
} ///:~
