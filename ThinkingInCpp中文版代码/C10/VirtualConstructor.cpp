//: C10:VirtualConstructor.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstddef>
#include <vector>
#include "../purge.h"
using namespace std;

class Shape {
    Shape* s; // ��ֹ��������͸�ֵ����
    Shape(Shape&);
    Shape operator=(Shape&);
protected:
    Shape() { s = 0; } // �ִ�C++Ӧ�ý�0�滻Ϊnullptr
public:
    virtual void draw() { s->draw(); }
    virtual void erase() { s->erase(); }
    virtual void test() { s->test(); }
    virtual ~Shape() {
        cout << "~Shape" << endl;
        if(s) {
            cout << "ִ�������: ";
            s->erase(); // �����
        }
        cout << "delete s: ";
        delete s; // ��̬delete
        // ��delete 0�ǺϷ��ģ����൱��һ��no-op�����޲�����
    }
    class BadShapeCreation : public logic_error {
    public:
        BadShapeCreation(string type)
            : logic_error("�޷��������� " + type) {}
    };
    Shape(string type) throw(BadShapeCreation);
};

class Circle : public Shape {
    Circle(Circle&);
    Circle operator=(Circle&);
    Circle() {} // ˽�й��캯��
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
    Square() {} // ˽�й��캯��
    friend class Shape;
public:
    void draw() { cout << "Square::draw" << endl; }
    void erase() { cout << "Square::erase" << endl; }
    void test() { draw(); }
    ~Square() { cout << "Square::~Square" << endl; }
};

// �鹹�캯��������������������������֮����ܶ���
Shape::Shape(string type) throw(Shape::BadShapeCreation) {
    if(type == "Circle") s = new Circle;
    else if(type == "Square") s = new Square;
    else throw BadShapeCreation(type);
    draw(); // ���캯���е������
}

char* sl[] = { "Circle", "Square", "Square",
               "Circle", "Circle", "Circle", "Square" };

int main() {
    vector<Shape*> shapes;
    cout << "�鹹�캯�����ã�" << endl;
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
        cout << "����" << endl;
        shapes[i]->test();
        cout << "��������" << endl;
        shapes[i]->erase();
    }
    Shape c("Circle"); // ��Ϊ�ֲ�������ջ�ϴ���
    cout << "�����������ã�" << endl;
    purge(shapes);
} ///:~
