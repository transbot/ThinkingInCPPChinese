//: C10:ShapeFactory2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory> // 使用智能指针
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~Shape() {}
};

// 抽象工厂接口
class AbstractShapeFactory {
public:
    virtual unique_ptr<Shape> createCircle() = 0;
    virtual unique_ptr<Shape> createSquare() = 0;
    virtual ~AbstractShapeFactory() {}
};

// 粗形状工厂类
class ThickShapeFactory : public AbstractShapeFactory {
public:
    unique_ptr<Shape> createCircle() override;
    unique_ptr<Shape> createSquare() override;
};

// 细形状工厂类
class ThinShapeFactory : public AbstractShapeFactory {
public:
    unique_ptr<Shape> createCircle() override;
    unique_ptr<Shape> createSquare() override;
};

// 粗形状的具体形状类
class ThickCircle : public Shape {
public:
    void draw() override { cout << "ThickCircle::draw" << endl; }
    void erase() override { cout << "ThickCircle::erase" << endl; }
    ~ThickCircle() { cout << "ThickCircle::~ThickCircle" << endl; }
};

class ThickSquare : public Shape {
public:
    void draw() override { cout << "ThickSquare::draw" << endl; }
    void erase() override { cout << "ThickSquare::erase" << endl; }
    ~ThickSquare() { cout << "ThickSquare::~ThickSquare" << endl; }
};

// 细形状的具体形状类
class ThinCircle : public Shape {
public:
    void draw() override { cout << "ThinCircle::draw" << endl; }
    void erase() override { cout << "ThinCircle::erase" << endl; }
    ~ThinCircle() { cout << "ThinCircle::~ThinCircle" << endl; }
};

class ThinSquare : public Shape {
public:
    void draw() override { cout << "ThinSquare::draw" << endl; }
    void erase() override { cout << "ThinSquare::erase" << endl; }
    ~ThinSquare() { cout << "ThinSquare::~ThinSquare" << endl; }
};

// 粗形状工厂方法的实现
unique_ptr<Shape> ThickShapeFactory::createCircle() {
    return make_unique<ThickCircle>();
}

unique_ptr<Shape> ThickShapeFactory::createSquare() {
    return make_unique<ThickSquare>();
}

// 细形状工厂方法的实现
unique_ptr<Shape> ThinShapeFactory::createCircle() {
    return make_unique<ThinCircle>();
}

unique_ptr<Shape> ThinShapeFactory::createSquare() {
    return make_unique<ThinSquare>();
}

// 用于初始化抽象工厂的单例
class ShapeFactoryInitializer {
    static ShapeFactoryInitializer si;
    static map<string, unique_ptr<AbstractShapeFactory>> factories;
    ShapeFactoryInitializer() {
        factories["Thick"] = make_unique<ThickShapeFactory>();
        factories["Thin"] = make_unique<ThinShapeFactory>();
    }
public:
    static AbstractShapeFactory& getFactory(const string& type) {
        if(factories.find(type) != factories.end())
            return *factories[type];
        else
            throw runtime_error("无法创建类型 " + type);
    }
};

// 静态成员定义
ShapeFactoryInitializer ShapeFactoryInitializer::si;
map<string, unique_ptr<AbstractShapeFactory>> ShapeFactoryInitializer::factories;

int main() {
    vector<unique_ptr<Shape>> shapes;
    try {
        // 使用粗形状工厂
        AbstractShapeFactory& thickFactory = ShapeFactoryInitializer::getFactory("Thick");
        shapes.push_back(thickFactory.createCircle());
        shapes.push_back(thickFactory.createSquare());

        // 使用细形状工厂
        AbstractShapeFactory& thinFactory = ShapeFactoryInitializer::getFactory("Thin");
        shapes.push_back(thinFactory.createCircle());
        shapes.push_back(thinFactory.createSquare());
    } catch(const runtime_error& e) {
        cout << e.what() << endl;
        return EXIT_FAILURE;
    }

    for(const auto& shape : shapes) {
        shape->draw();
        shape->erase();
    }
}
