//: C10:MessengerDemo.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <iostream>
#include <string>
using namespace std;

class Point { // A messenger
public:
  int x, y, z; // Since it's just a carrier
  Point(int xi, int yi, int zi) : x(xi), y(yi), z(zi) {}
  Point(const Point& p) :  x(p.x), y(p.y), z(p.z) {}
  Point& operator=(const Point& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
  }
  friend ostream&
  operator<<(ostream& os, const Point& p) {
    return os << "x=" << p.x << " y=" << p.y
              << " z=" << p.z;
  }
};

class Vector { // Mathematical vector
public:
  int magnitude, direction;
  Vector(int m, int d) : magnitude(m), direction(d) {}
};

class Space {
public:
  static Point translate(Point p, Vector v) {
    // Copy-constructor prevents modifying the original.
    // A dummy calculation:
    p.x += v.magnitude + v.direction;
    p.y += v.magnitude + v.direction;
    p.z += v.magnitude + v.direction;
    return p;
  }
};

int main() {
  Point p1(1, 2, 3);
  Point p2 = Space::translate(p1, Vector(11, 47));
  cout << "p1: " << p1 << " p2: " << p2 << endl;
} ///:~
