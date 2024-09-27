//: C06:MemFun1.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Applying pointers to member functions.
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
  vs.push_back(new Circle);
  vs.push_back(new Square);
  for_each(vs.begin(), vs.end(), mem_fun(&Shape::draw));
  purge(vs);
} ///:~
