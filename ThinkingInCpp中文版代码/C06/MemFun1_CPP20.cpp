//: C06:MemFun1_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 分别使用std::mem_fn和lambda 表达式来演示如何更方便地调用成员函数。
// 其中，std::mem_fn是一个函数对象（指针）适配器，能直接将成员函数指针转换为可调用对象。
// 而lambda 表达式提供了一种更简洁的方式来实现相同的功能。
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include "../purge.h"
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    virtual void draw() { cout << "Circle::Draw()" << endl; }
    ~Circle() { cout << "Circle::~Circle()" << endl; }
};

class Square : public Shape {
public:
    virtual void draw() { cout << "Square::Draw()" << endl; }
    ~Square() { cout << "Square::~Square()" << endl; }
};


int main() {
    vector<Shape*> vs;
    vs.push_back(new Circle); // 一个圆
    vs.push_back(new Square); // 一个正方形

    // 使用std::mem_fn
    for_each(vs.begin(), vs.end(), mem_fn(&Shape::draw));

    // 使用lambda表达式
    for_each(vs.begin(), vs.end(), [](Shape* shape) { shape->draw(); });
    purge(vs);
}