//: C10:MessengerDemo.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
#include <string>
using namespace std;

// ����һ��Point�࣬���ڱ�ʾ��ά�ռ��еĵ�
class Point { // һ����ʹ
public:
    int x, y, z; // ��ΪPoint��ֻ����Я�����ݣ����������Ϊpublic
    Point(int xi, int yi, int zi) : x(xi), y(yi), z(zi) {} // ��������
    Point(const Point& p) : x(p.x), y(p.y), z(p.z) {} // �������캯��
    Point& operator=(const Point& rhs) { // ������ֵ������
        x = rhs.x; y = rhs.y; z = rhs.z;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Point& p) { // �����������
        return os << "x=" << p.x << " y=" << p.y << " z=" << p.z;
    }
};

class Vector { // ��ѧ����
public:
    int magnitude, direction;
    Vector(int m, int d) : magnitude(m), direction(d) {}
};

class Space { // Space�ฺ����ռ��еĵ������
public:
    // ��̬��Ա����translate()���ڽ���p������vƽ��
    static Point translate(Point p, Vector v) {
        // �������캯����ֹ�޸�ԭʼ����
        // һ��ģ����㣺
        p.x += v.magnitude + v.direction;
        p.y += v.magnitude + v.direction;
        p.z += v.magnitude + v.direction;
        return p; // ����ƽ�ƺ�ĵ�
    }
};

int main() {
    Point p1(1, 2, 3);
    // p1������(11, 47)ƽ�ƣ��������p2
    Point p2 = Space::translate(p1, Vector(11, 47));
    cout << "p1: " << p1 << endl <<"p2: " << p2 << endl;
} ///:~
