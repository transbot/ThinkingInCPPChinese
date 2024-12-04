//: C10:ShapeFactory2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 多态工厂方法
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstddef>
#include "../purge.h"
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~Shape() {}
};

class ShapeFactory { // 形状工厂类
    virtual Shape* create() = 0;
    static map<string, ShapeFactory*> factories;
public:
    virtual ~ShapeFactory() {}
    friend class ShapeFactoryInitializer;
    class BadShapeCreation : public logic_error {
    public:
        BadShapeCreation(string type)
            : logic_error("无法创建类型 " + type) {}
    };
    static Shape* createShape(const string& id) throw(BadShapeCreation) {
        if(factories.find(id) != factories.end())
            return factories[id]->create();
        else
            throw BadShapeCreation(id);
    }
};

// 定义静态对象
map<string, ShapeFactory*> ShapeFactory::factories;

class Circle : public Shape {
    Circle() {} // 私有构造函数
    friend class ShapeFactoryInitializer;
    class Factory;
    friend class Factory;
    class Factory : public ShapeFactory {
    public:
        Shape* create() { return new Circle; }
        friend class ShapeFactoryInitializer;
    };
public:
    void draw() { cout << "Circle::draw" << endl; }
    void erase() { cout << "Circle::erase" << endl; }
    ~Circle() { cout << "Circle::~Circle" << endl; }
};

class Square : public Shape {
    Square() {} // 私有构造函数
    friend class ShapeFactoryInitializer;
    class Factory;
    friend class Factory;
    class Factory : public ShapeFactory {
    public:
        Shape* create() { return new Square; }
        friend class ShapeFactoryInitializer;
    };
public:
    void draw() { cout << "Square::draw" << endl; }
    void erase() { cout << "Square::erase" << endl; }
    ~Square() { cout << "Square::~Square" << endl; }
};

// 用于初始化ShapeFactory的单例
class ShapeFactoryInitializer {
    static ShapeFactoryInitializer si;
    ShapeFactoryInitializer() {
        ShapeFactory::factories["Circle"] = new Circle::Factory;
        ShapeFactory::factories["Square"] = new Square::Factory;
    }
    ~ShapeFactoryInitializer() {
        map<string, ShapeFactory*>::iterator it = ShapeFactory::factories.begin();
        while(it != ShapeFactory::factories.end())
            delete it++->second;
    }
};

// 静态成员定义
ShapeFactoryInitializer ShapeFactoryInitializer::si;

char* sl[] = { "Circle", "Square", "Square", "Circle", "Circle", "Circle", "Square" };

int main() {
    vector<Shape*> shapes;
    try {
        for(size_t i = 0; i < sizeof sl / sizeof sl[0]; i++)
            shapes.push_back(ShapeFactory::createShape(sl[i]));
    } catch(ShapeFactory::BadShapeCreation e) {
        cout << e.what() << endl;
        return EXIT_FAILURE;
    }
    for(size_t i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
        shapes[i]->erase();
    }
    purge(shapes);
} ///:~
