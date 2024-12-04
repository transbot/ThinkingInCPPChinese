//: C10:KissingPrincess2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用状态模式
#include <iostream>
#include <string>
using namespace std;

class Creature {
    // 定义一个状态接口
    class State {
    public:
        virtual string response() = 0; // 纯虚函数，定义响应行为
    };

    // 定义青蛙状态类
    class Frog : public State {
    public:
        string response() { return "呱呱!"; } // 青蛙的响应
    };

    // 定义王子状态类
    class Prince : public State {
    public:
        string response() { return "亲爱的!"; } // 王子的响应
    };

    State* state; // 当前状态指针

public:
    // 构造函数，初始状态为青蛙
    Creature() : state(new Frog()) {}

    // 打招呼，根据当前状态返回不同的响应
    void greet() { cout << state->response() << endl; }

    // 亲吻，将状态从青蛙变为王子
    void kiss() {
        delete state; // 销毁当前状态对象
        state = new Prince(); // 创建新的王子状态对象
    }

    // 析构函数，释放状态对象
    ~Creature() {
        delete state;
    }
};

int main() {
    Creature creature; // 创建一个生物对象，初始状态是青蛙
    creature.greet();  // 青蛙打招呼
    creature.kiss();   // 亲吻青蛙，青蛙变成王子
    creature.greet();  // 王子打招呼
} ///:~