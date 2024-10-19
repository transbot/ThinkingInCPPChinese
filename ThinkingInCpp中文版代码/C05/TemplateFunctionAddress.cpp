//: C05:TemplateFunctionAddress.cpp {-mwcc}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
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
