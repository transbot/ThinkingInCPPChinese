//: C09:Dominance.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

class Top {
public:
    virtual ~Top() {}
    virtual void f() {}
};

class Left : virtual public Top {
public:
    void f() {}
};

class Right : virtual public Top {};

class Bottom : public Left, public Right {};

int main() {
    Bottom b;
    b.f(); // ����Left::f()
} ///:~
