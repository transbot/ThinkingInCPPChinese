//: C05:MemberClass.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ��Ա��ģ��
#include <iostream>
#include <typeinfo>
using namespace std;

template<class T>
class Outer {
public:
    template<class R>
    class Inner {
    public:
        void f();
    };
};

template<class T>
template<class R>
void Outer<T>::Inner<R>::f() {
    cout << "����� == " << typeid(T).name() << endl;
    cout << "�ڲ��� == " << typeid(R).name() << endl;
    cout << "��ǰ����������������� == " << typeid(*this).name() << endl;
}

int main() {
    Outer<int>::Inner<bool> inner;
    inner.f();
} ///:~
