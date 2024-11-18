//: C07:Stlshape2_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ������ָ�������Դ�Զ�����
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
        shape->draw(); // ����ÿ����״�� draw �������Ӷ���������������
    }

    // ����ָ�������������ʱ�Զ��ͷ��ڴ�
} ///:~