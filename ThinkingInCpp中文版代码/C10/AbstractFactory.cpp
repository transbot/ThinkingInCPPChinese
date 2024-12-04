//: C10:AbstractFactory.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 游戏环境
#include <iostream>
using namespace std;

// 抽象障碍物类
class Obstacle {
public:
    virtual void action() = 0; // 纯虚函数，子类必须实现
};

// 抽象玩家类
class Player {
public:
    virtual void interactWith(Obstacle*) = 0; // 纯虚函数，子类必须实现
};

// 具体玩家类：Kitty
class Kitty : public Player {
public:
    virtual void interactWith(Obstacle* ob) {
        cout << "Kitty遇到了一个"; // 输出Kitty遇到障碍物的信息
        ob->action(); // 调用障碍物的action方法
    }
};

// 具体玩家类：KungFuGuy
class KungFuGuy : public Player {
public:
    virtual void interactWith(Obstacle* ob) {
        cout << "KungFuGuy现在正在对抗一个"; // 输出KungFuGuy对抗障碍物的信息
        ob->action(); // 调用障碍物的action方法
    }
};

// 具体障碍物类：Puzzle
class Puzzle : public Obstacle {
public:
    void action() {
        cout << "谜题" << endl; // 输出谜题的信息
    }
};

// 具体障碍物类：NastyWeapon
class NastyWeapon : public Obstacle {
public:
    void action() {
        cout << "致命武器" << endl; // 输出致命武器的信息
    }
};

// 抽象工厂类
class GameElementFactory {
public:
    virtual Player* makePlayer() = 0; // 纯虚函数，子类必须实现
    virtual Obstacle* makeObstacle() = 0; // 纯虚函数，子类必须实现
};

// 具体工厂类：KittiesAndPuzzles
class KittiesAndPuzzles : public GameElementFactory {
public:
    virtual Player* makePlayer() {
        return new Kitty; // 创建玩家Kitty
    }
    virtual Obstacle* makeObstacle() {
        return new Puzzle; // 创建障碍物Puzzle
    }
};

// 具体工厂类：KillAndDismember
class KillAndDismember : public GameElementFactory {
public:
    virtual Player* makePlayer() {
        return new KungFuGuy; // 创建玩家KungFuGuy
    }
    virtual Obstacle* makeObstacle() {
        return new NastyWeapon; // 创建障碍物NastyWeapon
    }
};

// 游戏环境类
class GameEnvironment {
    GameElementFactory* gef; // 工厂对象
    Player* p; // 玩家对象
    Obstacle* ob; // 障碍物对象
public:
    // 构造函数，初始化工厂、玩家和障碍物
    GameEnvironment(GameElementFactory* factory)
        : gef(factory), p(factory->makePlayer()), ob(factory->makeObstacle()) {}
    
    // 游戏玩法
    void play() {
        p->interactWith(ob); // 玩家与障碍物互动
    }
    
    // 析构函数，释放资源
    ~GameEnvironment() {
        delete p;   // 释放玩家对象
        delete ob;  // 释放障碍物对象
        delete gef; // 释放工厂对象
    }
};

int main() {
    // 创建两个游戏环境，分别使用不同的工厂
    GameEnvironment g1(new KittiesAndPuzzles), g2(new KillAndDismember);
    
    // 开始游戏
    g1.play(); // Kitty遇到谜题
    g2.play(); // KungFuGuy对抗致命武器
} /* 输出：
Kitty遇到了一个谜题
KungFuGuy现在正在对抗一个致命武器
*/