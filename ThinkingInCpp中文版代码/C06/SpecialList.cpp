//: C06:SpecialList.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用transform()的第二个版本
#include <algorithm>
#include <ctime>
#include <vector>
#include "Inventory.h"
#include "PrintSequence.h"
using namespace std;

struct Discounter {
    Inventory operator()(const Inventory& inv, float discount) {
        return Inventory(inv.getItem(), inv.getQuantity(),
                         int(inv.getValue() * (1 - discount)));
    }
};

struct DiscGen {
    float operator()() {
        float r = float(rand() % 10);
        return r / 100.0;
    }
};

int main() {
    vector<Inventory> vi;
    srand(time(0)); // 随机化
    generate_n(back_inserter(vi), 15, InvenGen());
    print(vi.begin(), vi.end(), "vi");

    vector<float> disc;
    generate_n(back_inserter(disc), 15, DiscGen());
    print(disc.begin(), disc.end(), "折扣：");

    vector<Inventory> discounted;
    transform(vi.begin(), vi.end(), disc.begin(),
              back_inserter(discounted), Discounter());
    print(discounted.begin(), discounted.end(), "打折后");
} ///:~
