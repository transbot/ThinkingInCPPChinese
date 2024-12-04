//: C10:KissingPrincess.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 以下代码未使用“状态”模式
#include <iostream>
using namespace std;

class Creature {
    bool isFrog; // 是青蛙吗
public:
    Creature() : isFrog(true) {}
    void greet() {
        if (isFrog) // 如果是青蛙，就用“呱呱”来打招呼
            cout << "呱呱!" << endl;
        else // 否则就是王子，那么用“亲爱的”来打招呼
            cout << "亲爱的!" << endl;
    }
    void kiss() { 
        isFrog = false; // 亲吻后，青蛙变成王子
    }
};

int main() {
    Creature creature; // 创建一个生物对象，初始状态是青蛙
    creature.greet();  // 青蛙打招呼
    creature.kiss();   // 亲吻青蛙，青蛙变成王子
    creature.greet();  // 王子打招呼
} ///:~
