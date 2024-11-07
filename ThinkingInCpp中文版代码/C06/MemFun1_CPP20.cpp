//: C06:MemFun1_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �ֱ�ʹ��std::mem_fn��lambda ���ʽ����ʾ��θ�����ص��ó�Ա������
// ���У�std::mem_fn��һ����������ָ�룩����������ֱ�ӽ���Ա����ָ��ת��Ϊ�ɵ��ö���
// ��lambda ���ʽ�ṩ��һ�ָ����ķ�ʽ��ʵ����ͬ�Ĺ��ܡ�
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include "../purge.h"
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    virtual void draw() { cout << "Circle::Draw()" << endl; }
    ~Circle() { cout << "Circle::~Circle()" << endl; }
};

class Square : public Shape {
public:
    virtual void draw() { cout << "Square::Draw()" << endl; }
    ~Square() { cout << "Square::~Square()" << endl; }
};


int main() {
    vector<Shape*> vs;
    vs.push_back(new Circle); // һ��Բ
    vs.push_back(new Square); // һ��������

    // ʹ��std::mem_fn
    for_each(vs.begin(), vs.end(), mem_fn(&Shape::draw));

    // ʹ��lambda���ʽ
    for_each(vs.begin(), vs.end(), [](Shape* shape) { shape->draw(); });
    purge(vs);
}