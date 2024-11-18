//: C07:Stlshape2_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用智能指针进行资源自动清理
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override { cout << "Circle::draw" << endl; }
    ~Circle() override { cout << "~Circle" << endl; }
};

class Triangle : public Shape {
public:
    void draw() const override { cout << "Triangle::draw" << endl; }
    ~Triangle() override { cout << "~Triangle" << endl; }
};

class Square : public Shape {
public:
    void draw() const override { cout << "Square::draw" << endl; }
    ~Square() override { cout << "~Square" << endl; }
};

int main() {
    typedef vector<unique_ptr<Shape>> Container;
    typedef Container::iterator Iter;
    Container shapes;
    shapes.emplace_back(make_unique<Circle>());
    shapes.emplace_back(make_unique<Square>());
    shapes.emplace_back(make_unique<Triangle>());

    for (const auto& shape : shapes) {
        shape->draw(); // 调用每个形状的 draw 方法，从而把它“画”出来
    }

    // 智能指针会在容器销毁时自动释放内存
} ///:~