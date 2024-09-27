//: C01:HasDestructor.cpp {O}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
class HasDestructor {
public:
  ~HasDestructor() {}
};

void g(); // For all we know, g may throw.

void f() {
  HasDestructor h;
  g();
} ///:~
