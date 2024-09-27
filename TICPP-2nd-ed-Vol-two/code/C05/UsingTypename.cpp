//: C05:UsingTypename.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Using 'typename' in the template argument list.

template<typename T> class X {};

int main() {
  X<int> x;
} ///:~
