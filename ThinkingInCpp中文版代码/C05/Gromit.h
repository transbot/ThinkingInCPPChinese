//: C05:Gromit.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// Gromit（阿高）是一只科技狗（techno-dog），其成员函数能获取不同数量的实参
#include <iostream>
class Gromit {
    int arf;
    int totalBarks;
public:
    // 成员变量arf被初始化为arf + 1
    Gromit(int arf = 1) : arf(arf + 1), totalBarks(0) {}

    // 让阿高叫；根据arf（汪）的值来决定叫多少声
    // 每个对象根据其实例化时的arf值来输出不同次数的 "汪! "
    void speak(int) {
        for(int i = 0; i < arf; i++) {
            std::cout << "汪! ";
            ++totalBarks;
        }
        std::cout << std::endl;
    }

    // 模拟阿高吃饭
    // const声明该函数不会修改对象的成员变量
    char eat(float) const {
        std::cout << "我吃吃吃!" << std::endl;
        return 'z';
    }

    // 模拟阿高睡觉
    // const声明该函数不会修改对象的成员变量
    int sleep(char, double) const {
        std::cout << "zzz..." << std::endl;
        return 0;
    }

    // 模拟阿高坐下
    // const声明该函数不会修改对象的成员变量
    void sit() const {
        std::cout << "正在坐下..." << std::endl;
    }
}; ///:~
