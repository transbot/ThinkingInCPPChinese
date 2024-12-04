//: C10:BuildBicycles.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} Bicycle

// 建造者设计模式
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>
#include "Bicycle.h"
#include "../purge.h"
using namespace std;

// 通过具体建造者来构建自行车
Bicycle* buildMeABike(
    BicycleTechnician& t,
    BicycleBuilder* builder
) {
    t.setBuilder(builder);
    t.construct();
    Bicycle* b = builder->getProduct();
    cout << "构建了一辆" << builder->getBikeName() << endl;
    return b;
}

int main() {
    // 创建一些自行车订单
    map<string, size_t> order;
    order["山地车"] = 2;
    order["旅行车"] = 1;
    order["赛车"] = 3;

    // 构建自行车
    vector<Bicycle*> bikes;
    BicycleBuilder* m = new MountainBikeBuilder;
    BicycleBuilder* t = new TouringBikeBuilder;
    BicycleBuilder* r = new RacingBikeBuilder;
    BicycleTechnician tech;
    map<string, size_t>::iterator it = order.begin();
    while(it != order.end()) {
        BicycleBuilder* builder;
        if(it->first == "山地车") builder = m;
        else if(it->first == "旅行车") builder = t;
        else if(it->first == "赛车") builder = r;
        for(size_t i = 0; i < it->second; ++i)
            bikes.push_back(buildMeABike(tech, builder));
        ++it;
    }
    delete m;
    delete t;
    delete r;

    // 显示库存
    for(size_t i = 0; i < bikes.size(); ++i)
        cout << "自行车: " << *bikes[i] << endl;
    purge(bikes);
}
/* 程序输出:
构建了一辆旅行车
构建了一辆赛车
构建了一辆赛车
构建了一辆赛车
构建了一辆山地车
构建了一辆山地车
自行车: { 车架 车轮 座椅 变速器 车把 链轮 货架 }
自行车: { 车架 车轮 座椅 车把 链轮 }
自行车: { 车架 车轮 座椅 车把 链轮 }
自行车: { 车架 车轮 座椅 车把 链轮 }
自行车: { 车架 车轮 座椅 变速器 车把 链轮 减震器 }
自行车: { 车架 车轮 座椅 变速器 车把 链轮 减震器 }
*/ ///:~
