//: C05:Box2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Defines non-template operators.
#include <iostream>
using namespace std;

template<class T> class Box {
  T t;
public:
  Box(const T& theT) : t(theT) {}
  friend Box<T> operator+(const Box<T>& b1,
                          const Box<T>& b2) {
    return Box<T>(b1.t + b2.t);
  }
  friend ostream&
  operator<<(ostream& os, const Box<T>& b) {
    return os << '[' << b.t << ']';
  }
};

int main() {
  Box<int> b1(1), b2(2);
  cout << b1 + b2 << endl; // [3]
  cout << b1 + 2 << endl; // [3]
} ///:~
