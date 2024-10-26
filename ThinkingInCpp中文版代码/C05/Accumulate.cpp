//: C05:Accumulate.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 编译时将一个“函数”作为参数传递
#include <iostream>
using namespace std;

// 累加F(0)到F(n)的结果
template<int n, template<int> class F> struct Accumulate {
    enum { val = Accumulate<n-1, F>::val + F<n>::val };
};

// 停止条件（返回F(0)的值）
template<template<int> class F> struct Accumulate<0, F> {
    enum { val = F<0>::val };
};

// 各种“函数”：
template<int n> struct Identity {
    enum { val = n };
};

template<int n> struct Square { // 平方
    enum { val = n*n };
};

template<int n> struct Cube {   // 立方
    enum { val = n*n*n };
};

int main() {
    cout << Accumulate<4, Identity>::val << endl; // 1-4累加：10
    cout << Accumulate<4, Square>::val << endl;   // 1-4分别求平方后相加：30
    cout << Accumulate<4, Cube>::val << endl;     // 1-4分别求立方后相加：100
} ///:~
