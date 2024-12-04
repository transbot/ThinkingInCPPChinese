//: C10:FibonacciAdapter.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 将现有的接口与一个目标接口适配
#include <iostream>
#include <numeric>
#include "FibonacciGenerator.h"
#include "../C06/PrintSequence.h"
using namespace std;

class FibonacciAdapter {
    // 生成迭代器
    FibonacciGenerator f; // 内部使用的斐波那契数生成器
    int length; // 序列的长度

public:
    // 构造函数，初始化序列长度
    FibonacciAdapter(int size) : length(size) {}

    // 定义内部迭代器类
    class iterator;
    friend class iterator; // 迭代器类是FibonacciAdapter的友元类

    // 迭代器类，继承自标准输入迭代器
    class iterator : public std::iterator<std::input_iterator_tag, FibonacciAdapter, ptrdiff_t> {
        FibonacciAdapter& ap; // 引用外部的FibonacciAdapter对象

    public:
        typedef int value_type; // 迭代器的值类型为int

        // 构造函数，初始化迭代器
        iterator(FibonacciAdapter& a) : ap(a) {}

        // 比较两个迭代器是否相等
        bool operator==(const iterator& other) const {
            return ap.f.count() == ap.length;
        }

        // 比较两个迭代器是否不相等
        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }

        // 解引用迭代器，返回当前斐波那契数
        int operator*() const {
            return ap.f();
        }

        // 前缀递增迭代器
        iterator& operator++() {
            return *this;
        }

        // 后缀递增迭代器
        iterator operator++(int) {
            iterator temp = *this;
            return temp;
        }
    };

    // 返回序列的起始迭代器
    iterator begin() {
        return iterator(*this);
    }

    // 返回序列的结束迭代器
    iterator end() {
        return iterator(*this);
    }
};

int main() {
    const int SZ = 20; // 序列长度

    // 创建一个长度为20的斐波那契数列适配器
    FibonacciAdapter a1(SZ);

    // 计算斐波那契数列的累加和
    cout << "accumulate(累加和): " << accumulate(a1.begin(), a1.end(), 0) << endl;

    // 创建两个长度为20的斐波那契数列适配器
    FibonacciAdapter a2(SZ), a3(SZ);

    // 计算两个斐波那契数列的内积
    cout << "inner product(内积): " 
         << inner_product(a2.begin(), a2.end(), a3.begin(), 0) << endl;

    // 创建一个长度为20的斐波那契数列适配器
    FibonacciAdapter a4(SZ);

    // 计算斐波那契数列的部分和
    int r1[SZ] = {0};
    int* end1 = partial_sum(a4.begin(), a4.end(), r1);
    print(r1, end1, "partial_sum(部分和)", " ");

    // 创建一个长度为20的斐波那契数列适配器
    FibonacciAdapter a5(SZ);

    // 计算斐波那契数列的相邻差值
    int r2[SZ] = {0};
    int* end2 = adjacent_difference(a5.begin(), a5.end(), r2);
    print(r2, end2, "adjacent_difference(相邻差)", " ");
} ///:~