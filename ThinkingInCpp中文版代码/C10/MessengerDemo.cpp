//: C10:MessengerDemo.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
#include <string>
using namespace std;

// 定义一个Point类，用于表示三维空间中的点
class Point { // 一个信使
public:
    int x, y, z; // 因为Point类只负责携带数据，因此数据设为public
    Point(int xi, int yi, int zi) : x(xi), y(yi), z(zi) {} // 拷贝函数
    Point(const Point& p) : x(p.x), y(p.y), z(p.z) {} // 拷贝构造函数
    Point& operator=(const Point& rhs) { // 拷贝赋值操作符
        x = rhs.x; y = rhs.y; z = rhs.z;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Point& p) { // 重载流插入符
        return os << "x=" << p.x << " y=" << p.y << " z=" << p.z;
    }
};

class Vector { // 数学向量
public:
    int magnitude, direction;
    Vector(int m, int d) : magnitude(m), direction(d) {}
};

class Space { // Space类负责处理空间中的点和向量
public:
    // 静态成员函数translate()用于将点p沿向量v平移
    static Point translate(Point p, Vector v) {
        // 拷贝构造函数禁止修改原始对象
        // 一个模拟计算：
        p.x += v.magnitude + v.direction;
        p.y += v.magnitude + v.direction;
        p.z += v.magnitude + v.direction;
        return p; // 返回平移后的点
    }
};

int main() {
    Point p1(1, 2, 3);
    // p1沿向量(11, 47)平移，结果存入p2
    Point p2 = Space::translate(p1, Vector(11, 47));
    cout << "p1: " << p1 << endl <<"p2: " << p2 << endl;
} ///:~
