//: C10:ShapeFactory1.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 形状工厂
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <string>
#include <vector>
#include "../purge.h"
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~Shape() {}
    
    class BadShapeCreation : public logic_error {
    public:
        BadShapeCreation(string type)
            : logic_error("无法创建类型 " + type) {}
    };
    
    // 静态的对象“生产”方法
    static Shape* factory(const string& type) throw(BadShapeCreation);
};

class Circle : public Shape { // 圆
    Circle() {} // 私有构造函数
    friend class Shape;
public:
    void draw() { cout << "Circle::draw" << endl; }
    void erase() { cout << "Circle::erase" << endl; }
    ~Circle() { cout << "Circle::~Circle" << endl; }
};

class Square : public Shape { // 正方形
    Square() {} // 私有构造函数
    friend class Shape;
public:
    void draw() { cout << "Square::draw" << endl; }
    void erase() { cout << "Square::erase" << endl; }
    ~Square() { cout << "Square::~Square" << endl; }
};

// 实现对象工厂模式必备的对象“生产”方法
Shape* Shape::factory(const string& type) throw(Shape::BadShapeCreation) {
    if(type == "Circle") return new Circle;
    if(type == "Square") return new Square;
    throw BadShapeCreation(type);
}

char* sl[] = { "Circle", "Square", "Square", "Circle", "Circle", "Circle", "Square" };

int main() {
    vector<Shape*> shapes;
    try {
        for(size_t i = 0; i < sizeof sl / sizeof sl[0]; i++)
            shapes.push_back(Shape::factory(sl[i]));
    } catch(Shape::BadShapeCreation e) {
        cout << e.what() << endl;
        purge(shapes);
        return EXIT_FAILURE;
    }
    for(size_t i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
        shapes[i]->erase();
    }
    purge(shapes);
} ///:~
