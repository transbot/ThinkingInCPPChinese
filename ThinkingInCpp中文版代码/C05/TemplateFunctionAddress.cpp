//: C05:TemplateFunctionAddress.cpp {-mwcc}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
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
