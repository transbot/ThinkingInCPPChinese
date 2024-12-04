//: C10:ChainOfReponsibility.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 模拟5岁小孩讨要东西
// 在这个示例程序中，所有家长构成了一个“责任链”
#include <iostream>
#include <vector>
#include "../purge.h"
using namespace std;

// 向家长讨一样东西，结果要么同意，要么是拒绝
enum Answer { NO, YES }; 

class GimmeStrategy { // 讨东西的策略
public:
    virtual Answer canIHave() = 0; // 纯虚函数，定义请求处理行为
    virtual ~GimmeStrategy() {}    // 虚析构函数，确保派生类对象正确销毁
};

class AskMom : public GimmeStrategy { // 如果是妈妈
public:
    Answer canIHave() {
        cout << "妈，我可以要这个吗？" << endl;
        return NO; // 妈妈拒绝
    }
};

class AskDad : public GimmeStrategy { // 如果是爸爸
public:
    Answer canIHave() {
        cout << "爸，我要这个！" << endl;
        return NO; // 爸爸拒绝
    }
};

class AskGrandpa : public GimmeStrategy { // 如果是爷爷
public:
    Answer canIHave() {
        cout << "爷爷，我都要过生日了！" << endl;
        return NO; // 爷爷拒绝
    }
};

class AskGrandma : public GimmeStrategy { // 如果是奶奶
public:
    Answer canIHave() {
        cout << "奶奶，我好爱你喔！" << endl;
        return YES; // 哦豁，奶奶同意了！
    }
};

class Gimme : public GimmeStrategy {
    vector<GimmeStrategy*> chain; // 策略链

public:
    Gimme() {
        // 初始化策略链，按顺序添加各个策略
        chain.push_back(new AskMom());     // 问妈要
        chain.push_back(new AskDad());     // 问爸要
        chain.push_back(new AskGrandpa()); // 问爷爷要 
        chain.push_back(new AskGrandma()); // 问奶奶要
    }

    Answer canIHave() { // 讨要东西的结果（YES或NO）
        // 遍历策略链，尝试每个策略
        vector<GimmeStrategy*>::iterator it = chain.begin();
        while(it != chain.end())
            if((*it++)->canIHave() == YES)
                return YES; // 如果某个策略成功，返回YES
        // 到达末尾仍未成功...
        cout << "呜呜!" << endl; // 表达失望
        return NO; // 返回NO，最终还是被拒绝了
    }

    ~Gimme() {        
        purge(chain); // 清理策略链中的所有对象
    }
};

int main() {
    Gimme chain; // 创建策略链
    chain.canIHave(); // 发起请求，看看谁会答应
} ///:~
