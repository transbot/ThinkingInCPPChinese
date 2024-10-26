//: C05:DelayedInstantiation.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ģ��ĳ�Ա��������Ҫʱ��ʵ����
class X {
public:
    void f() {}
};

class Y {
public:
    void g() {}
};

template<typename T> class Z {
    T t;
public:
    void a() { t.f(); }
    void b() { t.g(); }
};

int main() {
    Z<X> zx;
    zx.a(); // ���ᴴ�� Z<X>::b()
    Z<Y> zy;
    zy.b(); // ���ᴴ�� Z<Y>::a()
} ///:~
