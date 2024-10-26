//: C05:PartialOrder2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ��ģ��Ĳ�������ƫ��
#include <iostream>
using namespace std;

template<class T, class U> class C {
public:
    void f() { cout << "��ģ��\n"; }
};

template<class U> class C<int, U> {
public:
    void f() { cout << "T == int\n"; }
};

template<class T> class C<T, double> {
public:
    void f() { cout << "U == double\n"; }
};

template<class T, class U> class C<T*, U> {
public:
    void f() { cout << "ʹ����T*\n"; }
};

template<class T, class U> class C<T, U*> {
public:
    void f() { cout << "ʹ����U*\n"; }
};

template<class T, class U> class C<T*, U*> {
public:
    void f() { cout << "ʹ����T*��U*\n"; }
};

template<class T> class C<T, T> {
public:
    void f() { cout << "T == U\n"; }
};

int main() {
    C<float, int>().f();      // 1: ��ģ��
    C<int, float>().f();      // 2: T == int
    C<float, double>().f();   // 3: U == double
    C<float, float>().f();    // 4: T == U
    C<float*, float>().f();   // 5: ʹ����T* [T��float]
    C<float, float*>().f();   // 6: ʹ����U* [U��float]
    C<float*, int*>().f();    // 7: ʹ����T*��U* [float, int]

    // ��������������壺
    // 8: C<int, int>().f();
    // 9: C<double, double>().f();
    // 10: C<float*, float*>().f();
    // 11: C<int, int*>().f();
    // 12: C<int*, int*>().f();
} ///:~
