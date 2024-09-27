//: C05:TemplateFunctionAddress.cpp {-mwcc}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Taking the address of a function generated
// from a template.

template<typename T> void f(T*) {}

void h(void (*pf)(int*)) {}

template<typename T> void g(void (*pf)(T*)) {}

int main() {
  h(&f<int>); // Full type specification
  h(&f); // Type deduction
  g<int>(&f<int>); // Full type specification
  g(&f<int>); // Type deduction
  g<int>(&f); // Partial (but sufficient) specification
} ///:~
