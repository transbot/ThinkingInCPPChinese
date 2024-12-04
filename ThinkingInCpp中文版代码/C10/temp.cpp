//: C10:ShapeFactory2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory> // ʹ������ָ��
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~Shape() {}
};

// ���󹤳��ӿ�
class AbstractShapeFactory {
public:
    virtual unique_ptr<Shape> createCircle() = 0;
    virtual unique_ptr<Shape> createSquare() = 0;
    virtual ~AbstractShapeFactory() {}
};

// ����״������
class ThickShapeFactory : public AbstractShapeFactory {
public:
    unique_ptr<Shape> createCircle() override;
    unique_ptr<Shape> createSquare() override;
};

// ϸ��״������
class ThinShapeFactory : public AbstractShapeFactory {
public:
    unique_ptr<Shape> createCircle() override;
    unique_ptr<Shape> createSquare() override;
};

// ����״�ľ�����״��
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

// ϸ��״�ľ�����״��
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

// ����״����������ʵ��
unique_ptr<Shape> ThickShapeFactory::createCircle() {
    return make_unique<ThickCircle>();
}

unique_ptr<Shape> ThickShapeFactory::createSquare() {
    return make_unique<ThickSquare>();
}

// ϸ��״����������ʵ��
unique_ptr<Shape> ThinShapeFactory::createCircle() {
    return make_unique<ThinCircle>();
}

unique_ptr<Shape> ThinShapeFactory::createSquare() {
    return make_unique<ThinSquare>();
}

// ���ڳ�ʼ�����󹤳��ĵ���
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
            throw runtime_error("�޷��������� " + type);
    }
};

// ��̬��Ա����
ShapeFactoryInitializer ShapeFactoryInitializer::si;
map<string, unique_ptr<AbstractShapeFactory>> ShapeFactoryInitializer::factories;

int main() {
    vector<unique_ptr<Shape>> shapes;
    try {
        // ʹ�ô���״����
        AbstractShapeFactory& thickFactory = ShapeFactoryInitializer::getFactory("Thick");
        shapes.push_back(thickFactory.createCircle());
        shapes.push_back(thickFactory.createSquare());

        // ʹ��ϸ��״����
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
