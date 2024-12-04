//: C10:FibonacciGenerator.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#ifndef FIBONACCIGENERATOR_H
#define FIBONACCIGENERATOR_H

class FibonacciGenerator {
    int n;          // 当前生成的斐波那契数的位置（从0开始计数）
    int val[2];     // 该int数组存储最近两个生成的斐波那契数

public:
    // 构造函数，初始化斐波那契数的位置和值
    FibonacciGenerator() : n(0) { 
        val[0] = val[1] = 0; 
    }

    // 重载函数调用操作符，生成下一个斐波那契数
    int operator()() {
        int result = n > 2 ? val[0] + val[1] : n > 0 ? 1 : 0; // 根据位置计算斐波那契数
        ++n; // 更新位置
        val[0] = val[1]; // 更新前一个值
        val[1] = result; // 更新当前值
        return result;   // 返回生成的斐波那契数
    }

    // 获取已生成的斐波那契数的数量
    int count() { 
        return n; 
    }
};

#endif // FIBONACCIGENERATOR_H ///:~