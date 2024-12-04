//: C10:VirtualConstructor.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstddef>
#include <vector>
#include "../purge.h"
using namespace std;

class Shape {
    Shape* s; // 禁止拷贝构造和赋值操作
    Shape(Shape&);
    Shape operator=(Shape&);
protected:
    Shape() { s = 0; } // 现代C++应该将0替换为nullptr
public:
    virtual void draw() { s->draw(); }
    virtual void erase() { s->erase(); }
    virtual void test() { s->test(); }
    virtual ~Shape() {
        cout << "~Shape" << endl;
        if(s) {
            cout << "执行虚调用: ";
            s->erase(); // 虚调用
        }
        cout << "delete s: ";
        delete s; // 多态delete
        // （delete 0是合法的；它相当于一个no-op，即无操作）
    }
    class BadShapeCreation : public logic_error {
    public:
        BadShapeCreation(string type)
            : logic_error("无法创建类型 " + type) {}
    };
    Shape(string type) throw(BadShapeCreation);
};

class Circle : public Shape {
    Circle(Circle&);
    Circle operator=(Circle&);
    Circle() {} // 私有构造函数
    friend class Shape;
public:
    void draw() { cout << "Circle::draw" << endl; }
    void erase() { cout << "Circle::erase" << endl; }
    void test() { draw(); }
    ~Circle() { cout << "Circle::~Circle" << endl; }
};

class Square : public Shape {
    Square(Square&);
    Square operator=(Square&);
    Square() {} // 私有构造函数
    friend class Shape;
public:
    void draw() { cout << "Square::draw" << endl; }
    void erase() { cout << "Square::erase" << endl; }
    void test() { draw(); }
    ~Square() { cout << "Square::~Square" << endl; }
};

// 虚构造函数，必须在声明了所有派生类之后才能定义
Shape::Shape(string type) throw(Shape::BadShapeCreation) {
    if(type == "Circle") s = new Circle;
    else if(type == "Square") s = new Square;
    else throw BadShapeCreation(type);
    draw(); // 构造函数中的虚调用
}

char* sl[] = { "Circle", "Square", "Square",
               "Circle", "Circle", "Circle", "Square" };

int main() {
    vector<Shape*> shapes;
    cout << "虚构造函数调用：" << endl;
    try {
        for(size_t i = 0; i < sizeof sl / sizeof sl[0]; i++)
            shapes.push_back(new Shape(sl[i]));
    } catch(Shape::BadShapeCreation e) {
        cout << e.what() << endl;
        purge(shapes);
        return EXIT_FAILURE;
    }
    for(size_t i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
        cout << "测试" << endl;
        shapes[i]->test();
        cout << "结束测试" << endl;
        shapes[i]->erase();
    }
    Shape c("Circle"); // 作为局部变量在栈上创建
    cout << "析构函数调用：" << endl;
    purge(shapes);
} ///:~
