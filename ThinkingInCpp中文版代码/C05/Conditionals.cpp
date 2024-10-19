//: C05:Conditionals.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Uses compile-time conditions to choose code.
#include <iostream>
using namespace std;

template<bool cond> struct Select {};

template<> class Select<true> {
  static void statement1() {
    cout << "This is statement1 executing\n";
  }
public:
  static void f() { statement1(); }
};

template<> class Select<false> {
  static void statement2() {
    cout << "This is statement2 executing\n";
  }
public:
  static void f() { statement2(); }
};

template<bool cond> void execute() {
  Select<cond>::f();
}

int main() {
  execute<sizeof(int) == 4>();
} ///:~
