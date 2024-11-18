//: C08:Recycle2_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} Trash

// 使用map进行垃圾回收
// 修改了原书程序，使用智能指针管理垃圾对象的生命周期。
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <typeinfo>
#include <vector>
#include "Trash.h"
using namespace std;

// type_info指针的比较器
struct TInfoLess {
    bool operator()(const type_info* t1, const type_info* t2) const {
        return t1->before(*t2);
    }
};

typedef map<const type_info*, vector<unique_ptr<Trash>>, TInfoLess> TrashMap;

// 计算垃圾箱中垃圾的总价值
void sumValue(const TrashMap::value_type& p, ostream& os) {
    float val = 0;
    for (const auto& trash : p.second) {
        val += trash->weight() * trash->value();
        os << p.first->name() // type_info::name()
           << " 的重量 = " << trash->weight() << endl;
    }
    os << "总价值 = " << val << endl;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // 初始化随机数生成器

    // 随机填充垃圾箱
    TrashMap bin;
    for (int i = 0; i < 30; i++) {
        unique_ptr<Trash> tp;
        switch (rand() % 3) {
            case 0: tp = make_unique<Aluminum>(static_cast<float>((rand() % 1000) / 10.0)); break;
            case 1: tp = make_unique<Paper>(static_cast<float>((rand() % 1000) / 10.0)); break;
            case 2: tp = make_unique<Glass>(static_cast<float>((rand() % 1000) / 10.0)); break;
        }
        // 将unique_ptr转移到vector中，确保所有权转移。
        bin[&typeid(*tp)].push_back(move(tp));
    }

    // 打印分类后的每种垃圾的信息
    for (const auto& p : bin) {
        sumValue(p, cout);
    }

    return 0;
} ///:~