//: C07:Stlshape.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用STL vector来容纳Shape类的对象
#include <vector>
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() { cout << "Circle::draw" << endl; }
    ~Circle() { cout << "~Circle" << endl; }
};

class Triangle : public Shape {
public:
    void draw() { cout << "Triangle::draw" << endl; }
    ~Triangle() { cout << "~Triangle" << endl; }
};

class Square : public Shape {
public:
    void draw() { cout << "Square::draw" << endl; }
    ~Square() { cout << "~Square" << endl; }
};

int main() {
    typedef std::vector<Shape*> Container;
    typedef Container::iterator Iter;
    Container shapes;
    shapes.push_back(new Circle);
    shapes.push_back(new Square);
    shapes.push_back(new Triangle);
    for(Iter i = shapes.begin(); i != shapes.end(); i++)
        (*i)->draw(); // 调用每个形状的draw方法，从而把它“画”出来

    // ... 过了一段时间后：
    for(Iter j = shapes.begin(); j != shapes.end(); j++)
        delete *j; // 删除每个形状对象
} ///:~
