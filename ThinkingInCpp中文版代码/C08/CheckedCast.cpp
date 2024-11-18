//: C08:CheckedCast.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 在运行时执行经过验证的强制类型转换（checked cast）
#include <iostream>
#include <vector>
#include "../purge.h"
using namespace std;

class Security { // 证券
protected:
    enum { BASEID = 0 };
public:
    virtual ~Security() {} // 虚析构函数
    
    // 该虚函数用于检查对象的类型，所有派生类都要重写，
    // 用于检查对象是否属于当前类或其祖先类。
    virtual bool isA(int id) { return (id == BASEID); }
};

class Stock : public Security { // 股票
    typedef Security Super;
protected:
    enum { OFFSET = 1, TYPEID = BASEID + OFFSET };
public:
    bool isA(int id) {
        return id == TYPEID || Super::isA(id);
    }
    static Stock* dynacast(Security* s) {
        return (s->isA(TYPEID)) ? static_cast<Stock*>(s) : 0;
    }
};

class Bond : public Security { // 债券
    typedef Security Super;
protected:
    enum { OFFSET = 2, TYPEID = BASEID + OFFSET };
public:
    bool isA(int id) {
        return id == TYPEID || Super::isA(id);
    }
    static Bond* dynacast(Security* s) {
        return (s->isA(TYPEID)) ? static_cast<Bond*>(s) : 0;
    }
};

class Investment : public Security { // 投资
    typedef Security Super;
protected:
    enum { OFFSET = 3, TYPEID = BASEID + OFFSET };
public:
    bool isA(int id) {
        return id == TYPEID || Super::isA(id);
    }
    static Investment* dynacast(Security* s) {
        return (s->isA(TYPEID)) ? static_cast<Investment*>(s) : 0;
    }
    void special() {
        cout << "Investment的特殊函数" << endl;
    }
};

class Metal : public Investment { // 金属
    typedef Investment Super;
protected:
    enum { OFFSET = 4, TYPEID = BASEID + OFFSET };
public:
    bool isA(int id) {
        return id == TYPEID || Super::isA(id);
    }
    static Metal* dynacast(Security* s) {
        return (s->isA(TYPEID)) ? static_cast<Metal*>(s) : 0;
    }
};

int main() {
    vector<Security*> portfolio; // 创建一个存储不同类型证券的“资产组合”向量
    portfolio.push_back(new Metal); // 添加一个金属对象
    portfolio.push_back(new Investment); // 添加一个投资对象
    portfolio.push_back(new Bond); // 添加一个债券对象
    portfolio.push_back(new Stock); // 添加一个股票对象

    // 遍历portfolio向量，检查每个对象是不是Investment类型
    for(vector<Security*>::iterator it = portfolio.begin();
        it != portfolio.end(); ++it) {
        Investment* cm = Investment::dynacast(*it); // 尝试将Security指针转型为Investment指针
        if(cm) // 如果转型成功
            cm->special(); // 那么调用Investment的特殊函数
        else
            cout << "不是一个Investment" << endl; // 如果转型失败，输出提示信息
    }

    cout << "向继承层次结构的中间（级）指针的强制转换：" << endl;
    Security* sp = new Metal; // 创建一个指向Metal对象的Security指针
    Investment* cp = Investment::dynacast(sp); // 尝试将Security指针转型为Investment指针
    if(cp)
        cout << "它是一个Investment" << endl; // 如果转型成功，输出提示信息
    Metal* mp = Metal::dynacast(sp); // 尝试将Security指针转型为Metal指针
    if(mp)
        cout << "它也是一个Metal!" << endl; // 如果转型成功，输出提示信息

    purge(portfolio); // 清理portfolio中的所有对象
} ///:~