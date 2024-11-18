//: C08:ConstructorOrder.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ�����������������˳��
#include <iostream>
#include <typeinfo>
using namespace std;

template<int id>
class Announce {
public:
    Announce() {
        cout << typeid(*this).name() << " ���캯��" << endl;
    }
    ~Announce() {
        cout << typeid(*this).name() << " ��������" << endl;
    }
};

class X : public Announce<0> {
   // X���������Announce���͵ĳ�Ա����
    Announce<1> m1;
    Announce<2> m2;

public:
    X() { cout << "X::X()" << endl; }   // ���캯��
    ~X() { cout << "X::~X()" << endl; } // ��������
};

int main() {
    X x;
} ///:~
