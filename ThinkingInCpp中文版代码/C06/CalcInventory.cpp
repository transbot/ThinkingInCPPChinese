//: C06:CalcInventory.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// for_each()的更多例子
#include <algorithm>
#include <ctime>
#include <vector>
#include "Inventory.h"
#include "PrintSequence.h"
using namespace std;

// 计算库存总数量和总价格
class InvAccum {
    int quantity;
    int value;
public:
    InvAccum() : quantity(0), value(0) {}
    void operator()(const Inventory& inv) {
        quantity += inv.getQuantity();
        value += inv.getQuantity() * inv.getValue();
    }
    friend ostream& operator<<(ostream& os, const InvAccum& ia) {
        return os << "总数量: " << ia.quantity << ", 总价格: " << ia.value;
    }
};

int main() {
    vector<Inventory> vi;
    srand(time(0)); // 随机化
    generate_n(back_inserter(vi), 15, InvenGen());
    print(vi.begin(), vi.end(), "vi");
    InvAccum ia = for_each(vi.begin(), vi.end(), InvAccum());
    cout << ia << endl;
} ///:~
