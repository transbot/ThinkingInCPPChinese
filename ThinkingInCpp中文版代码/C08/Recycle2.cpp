//: C08:Recycle2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} Trash

// 使用map进行垃圾回收
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <typeinfo>
#include <utility>
#include <vector>
#include "Trash.h"
#include "../purge.h"
using namespace std;

// type_info指针的比较器
struct TInfoLess {
    bool operator()(const type_info* t1, const type_info* t2) const {
        return t1->before(*t2);
    }
};

typedef map<const type_info*, vector<Trash*>, TInfoLess> TrashMap;

// 计算垃圾箱中垃圾的总价值
void sumValue(const TrashMap::value_type& p, ostream& os) {
    vector<Trash*>::const_iterator tally = p.second.begin();
    float val = 0;
    while (tally != p.second.end()) {
        val += (*tally)->weight() * (*tally)->value();
        os << p.first->name() // type_info::name()
           << " 的重量 = " << (*tally)->weight() << endl;
        ++tally;
    }
    os << "总价值 = " << val << endl;
}

int main() {
    srand(time(0)); // 初始化随机数生成器

    // 随机填充垃圾箱
    TrashMap bin;
    for (int i = 0; i < 30; i++) {
        Trash* tp;
        switch (rand() % 3) {
            case 0: tp = new Aluminum((rand() % 1000) / 10.0); break;
            case 1: tp = new Paper((rand() % 1000) / 10.0); break;
            case 2: tp = new Glass((rand() % 1000) / 10.0); break;
        }
        bin[&typeid(*tp)].push_back(tp);
    }

    // 打印分类后的每种垃圾的信息
    for (TrashMap::iterator p = bin.begin(); p != bin.end(); ++p) {
        sumValue(*p, cout);
        purge(p->second);
    }
} ///:~
