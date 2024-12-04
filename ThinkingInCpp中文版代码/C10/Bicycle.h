//: C10:Bicycle.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 定义用于构建自行车的各种类
// 演示“建造者”设计模式
#ifndef BICYCLE_H
#define BICYCLE_H
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include "../purge.h"
using std::size_t;

// 定义自行车部件类
class BicyclePart {
public:
    // 定义自行车部件的枚举类型
    enum BPart { 
    FRAME,       // 车架
    WHEEL,       // 车轮
    SEAT,        // 座椅
    DERAILLEUR,  // 变速器
    HANDLEBAR,   // 车把
    SPROCKET,    // 链轮
    RACK,        // 货架
    SHOCK,       // 减震器
    NPARTS       // 部件总数
};
private:
    BPart id; // 部件标识符
    static std::string names[NPARTS]; // 部件名称数组
public:
    // 构造函数，设置部件的标识符
    BicyclePart(BPart bp) { id = bp; }
    // 友元函数，用于输出部件的名称
    friend std::ostream& operator<<(std::ostream& os, const BicyclePart& bp) {
        return os << bp.names[bp.id];
    }
};

// 定义自行车类
class Bicycle {
    std::vector<BicyclePart*> parts; // 该向量存储了自行车部件
public:
    // 析构函数，释放所有部件的内存
    ~Bicycle() { purge(parts); }
    // 将一个新的部件添加到自行车中
    void addPart(BicyclePart* bp) { parts.push_back(bp); }
    // 友元函数重载了流插入符，用于输出自行车的所有部件
    friend std::ostream& operator<<(std::ostream& os, const Bicycle& b) {
        os << "{ ";
        for(size_t i = 0; i < b.parts.size(); ++i)
            os << *b.parts[i] << ' ';
        return os << '}';
    }
};

// 定义自行车建造者抽象类
class BicycleBuilder {
protected:
    Bicycle* product; // 当前正在构建的自行车
public:    
    BicycleBuilder() { product = 0; } // 默认构造函数，将产品初始化为nullptr    
    void createProduct() { product = new Bicycle; } // 创建新的自行车产品    
    virtual void buildFrame() = 0; // 构建车架的虚函数    
    virtual void buildWheel() = 0; // 构建车轮的虚函数    
    virtual void buildSeat() = 0;  // 构建座椅的虚函数    
    virtual void buildDerailleur() = 0; // 构建变速器的虚函数    
    virtual void buildHandlebar() = 0;  // 构建车把的虚函数    
    virtual void buildSprocket() = 0;   // 构建链轮的虚函数    
    virtual void buildRack() = 0;       // 构建货架的虚函数    
    virtual void buildShock() = 0;      // 构建减震器的虚函数    
    virtual std::string getBikeName() const = 0; // 获取自行车名称的虚函数

    Bicycle* getProduct() { // 获取构建的产品
        Bicycle* temp = product; // 保存当前产品
        product = 0; // 放弃产品
        return temp;
    }
};

// 定义山地自行车建造者类
class MountainBikeBuilder : public BicycleBuilder {
public:    
    void buildFrame(); // 构建车架的具体实现    
    void buildWheel(); // 构建轮子的具体实现    
    void buildSeat();  // 构建座椅的具体实现    
    void buildDerailleur(); // 构建变速器的具体实现    
    void buildHandlebar();  // 构建车把的具体实现    
    void buildSprocket();   // 构建链轮的具体实现    
    void buildRack();       // 构建货架的具体实现    
    void buildShock();      // 构建减震器的具体实现
    
    // 获取山地自行车的名称
    std::string getBikeName() const { return "山地车";}
};

// 定义旅行车建造者类
class TouringBikeBuilder : public BicycleBuilder {
public:    
    void buildFrame();  // 构建车架的具体实现    
    void buildWheel();  // 构建轮子的具体实现    
    void buildSeat();   // 构建座椅的具体实现    
    void buildDerailleur(); // 构建变速器的具体实现    
    void buildHandlebar();  // 构建车把的具体实现    
    void buildSprocket();   // 构建链轮的具体实现    
    void buildRack();       // 构建货架的具体实现    
    void buildShock();      // 构建减震器的具体实现
    
    // 获取旅行车的名称
    std::string getBikeName() const { return "旅行车"; }
};

// 定义赛车建造者类
class RacingBikeBuilder : public BicycleBuilder {
public:    
    void buildFrame();  // 构建车架的具体实现    
    void buildWheel();  // 构建轮子的具体实现    
    void buildSeat();   // 构建座椅的具体实现    
    void buildDerailleur(); // 构建变速器的具体实现    
    void buildHandlebar();  // 构建车把的具体实现    
    void buildSprocket();   // 构建链轮的具体实现    
    void buildRack();       // 构建货架的具体实现    
    void buildShock();      // 构建减震器的具体实现
    
    // 获取赛车的名称
    std::string getBikeName() const { return "赛车"; }
};

// 定义自行车技工类
class BicycleTechnician {
    BicycleBuilder* builder; // 当前使用的建造者
public:
    // 默认构造函数，将建造者初始化为nullptr
    BicycleTechnician() { builder = 0; }
    // 设置当前使用的建造者
    void setBuilder(BicycleBuilder* b) { builder = b; }
    // 构建自行车
    void construct();
};
#endif // BICYCLE_H ///:~
