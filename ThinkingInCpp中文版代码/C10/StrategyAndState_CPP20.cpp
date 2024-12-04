//: C10:StrategyAndState_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// “策略”设计模式
#include <iostream>
using namespace std;

// 策略接口
class NameStrategy {
public:
    virtual void greet() = 0; // 纯虚函数，定义打招呼的行为
};

// 下面是三种忘记某人名字的情况
class SayHi : public NameStrategy { // 亲切地打招呼
public:
    void greet() override { // 实现打招呼行为
        cout << "你好！" << endl;
    }
};

class Ignore : public NameStrategy { // 视而不见
public:
    void greet() override { // 实现打招呼行为
        cout << "(假装没看见对方)" << endl;
    }
};

class Admission : public NameStrategy { // 老实承认忘记对方名字了 
public:
    void greet() override { // 实现打招呼行为
        cout << "对不起，请问您是？" << endl;
    }
};

// “上下文”控制策略
class Context {
    NameStrategy& strategy; // 引用当前使用的策略

public:
    Context(NameStrategy& strat) : strategy(strat) {} // 构造函数，初始化策略
    void greet() { // 调用当前策略的打招呼方法
        strategy.greet();
    }
};

int main() {
    SayHi sayhi; // 创建亲切打招呼的策略
    Ignore ignore; // 创建视而不见的策略
    Admission admission; // 创建老实承认忘记名字的策略

    // 创建三种不同的上下文，每种上下文使用不同的策略
    Context c1(sayhi), c2(ignore), c3(admission);
    c1.greet(); // 使用亲切打招呼的策略
    c2.greet(); // 使用视而不见的策略
    c3.greet(); // 使用老实承认忘记名字的策略
} ///:~