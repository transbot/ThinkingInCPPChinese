//: C07:Stlshape_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��STL vector������Shape��Ķ���
// ����ʹ������ָ���޸���ԭ����
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
    // ʹ��unique_ptr    
    typedef std::vector<std::unique_ptr<Shape>> Container;
    typedef Container::iterator Iter;
    Container shapes;
    shapes.push_back(std::make_unique<Circle>());
    shapes.push_back(std::make_unique<Square>());
    shapes.push_back(std::make_unique<Triangle>());
    for(Iter i = shapes.begin(); i != shapes.end(); i++)
        (*i)->draw(); // ����ÿ����״��draw�������Ӷ���������������

    // ����Ҫ�ֶ�ɾ����unique_ptr�����뿪������ʱ�Զ��ͷ�
} ///:~
