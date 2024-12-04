//: C10:BeeAndFlowers.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

//: C10:BeeAndFlowers.cpp
// 演示访问者模式
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "../purge.h"
using namespace std;

class Gladiolus;     // 剑兰
class Renuculus;     // 毛茛
class Chrysanthemum; // 菊花

// 访问者基类
class Visitor {
public:
    virtual void visit(Gladiolus* f) = 0;     // 访问剑兰对象
    virtual void visit(Renuculus* f) = 0;     // 访问毛茛对象
    virtual void visit(Chrysanthemum* f) = 0; // 访问菊花对象
    virtual ~Visitor() {}
};

// 花的基类
class Flower {
public:
    virtual void accept(Visitor&) = 0; // 接受访问者
    virtual ~Flower() {}
};

// 剑兰类
class Gladiolus : public Flower {
public:
    virtual void accept(Visitor& v) { v.visit(this); } // 接受访问者
};

// 毛茛类
class Renuculus : public Flower {
public:
    virtual void accept(Visitor& v) { v.visit(this); } // 接受访问者
};

// 菊花类
class Chrysanthemum : public Flower {
public:
    virtual void accept(Visitor& v) { v.visit(this); } // 接受访问者
};

// 添加生成字符串的能力
class StringVal : public Visitor {
    string s;
public:
    operator const string&() { return s; }
    virtual void visit(Gladiolus*) {
        s = "剑兰";
    }
    virtual void visit(Renuculus*) {
        s = "毛茛";
    }
    virtual void visit(Chrysanthemum*) {
        s = "菊花";
    }
};

// 在蜜蜂这种访问者中添加蜜蜂执行的操作
class Bee : public Visitor {
public:
    virtual void visit(Gladiolus*) {
        cout << "蜜蜂和剑兰" << endl;
    }
    virtual void visit(Renuculus*) {
        cout << "蜜蜂和毛茛" << endl;
    }
    virtual void visit(Chrysanthemum*) {
        cout << "蜜蜂和菊花" << endl;
    }
};

// 随机生成Flower对象
struct FlowerGen {
    Flower* operator()() {
        switch(rand() % 3) {
            default:
            case 0: return new Gladiolus;      // 生成剑兰对象
            case 1: return new Renuculus;      // 生成毛茛对象
            case 2: return new Chrysanthemum;  // 生成菊花对象
        }
    }
};

int main() {
    srand(time(0)); // 初始化随机数生成器
    vector<Flower*> v(10);
    generate(v.begin(), v.end(), FlowerGen());
    vector<Flower*>::iterator it;
    
    // 类似于为Flower添加了生成字符串表示的虚函数
    StringVal sval;
    for(it = v.begin(); it != v.end(); it++) {
        (*it)->accept(sval);
        cout << string(sval) << endl;
    }
    
    // 对所有Flower执行“蜜蜂”的操作
    Bee bee;
    for(it = v.begin(); it != v.end(); it++)
        (*it)->accept(bee);
    purge(v);
} ///:~
