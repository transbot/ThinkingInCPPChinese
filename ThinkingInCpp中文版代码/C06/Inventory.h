//: C06:Inventory.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <cstdlib>
using std::rand;

class Inventory {
    char item;     // 名称
    int quantity;  // 数量
    int value;     // 单价
public:
    Inventory(char it, int quant, int val)
    : item(it), quantity(quant), value(val) {}
    // 可以接受复合赋值操作符和拷贝构造函数
    char getItem() const { return item; }
    int getQuantity() const { return quantity; }
    void setQuantity(int q) { quantity = q; }
    int getValue() const { return value; }
    void setValue(int val) { value = val; }
    friend std::ostream& operator<<(std::ostream& os, const Inventory& inv) {
        return os << inv.item << ": " << "数量 " << inv.quantity 
                  << ", 单价 " << inv.value;
    }
};

// 生成器
struct InvenGen {
    Inventory operator()() {
        static char c = 'a';
        int q = rand() % 100;
        int v = rand() % 500;
        return Inventory(c++, q, v);
    }
};
#endif // INVENTORY_H  ///:~
