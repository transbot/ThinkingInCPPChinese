//: C01:InitExcept.cpp {-bor}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Handles exceptions from subobjects.
#include <iostream>
using namespace std;

class Base {
  int i;
public:
  class BaseExcept {};
  Base(int i) : i(i) { throw BaseExcept(); }
};

class Derived : public Base {
public:
  class DerivedExcept {
    const char* msg;
  public:
    DerivedExcept(const char* msg) : msg(msg) {}
    const char* what() const { return msg; }
  };
  Derived(int j) try : Base(j) {
    // Constructor body
    cout << "This won't print" << endl;
  } catch(BaseExcept&) {
    throw DerivedExcept("Base subobject threw");;
  }
};

int main() {
  try {
    Derived d(3);
  } catch(Derived::DerivedExcept& d) {
    cout << d.what() << endl;  // "Base subobject threw"
  }
} ///:~
