//: C09:VirtualBase3.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ�����������ȷʵ��
#include <iostream>
using namespace std;

class Top {
    int x;
public:
    Top(int n) { x = n; }
    virtual ~Top() {}
    friend ostream& operator<<(ostream& os, const Top& t) {
        return os << t.x;
    }
};

class Left : virtual public Top {
    int y;
protected:
    void specialPrint(ostream& os) const {
        os << ',' << y;
    }
public:
    Left(int m, int n) : Top(m) { y = n; }
    friend ostream& operator<<(ostream& os, const Left& l) {
        return os << static_cast<const Top&>(l) << ',' << l.y;
    }
};

class Right : virtual public Top {
    int z;
protected:
    void specialPrint(ostream& os) const {
        os << ',' << z;
    }
public:
    Right(int m, int n) : Top(m) { z = n; }
    friend ostream& operator<<(ostream& os, const Right& r) {
        return os << static_cast<const Top&>(r) << ',' << r.z;
    }
};

class Bottom : public Left, public Right {
    int w;
public:
    Bottom(int i, int j, int k, int m) :
        Top(i), Left(0, j), Right(0, k) { w = m; }
    friend ostream& operator<<(ostream& os, const Bottom& b) {
        os << static_cast<const Top&>(b);
        b.Left::specialPrint(os);
        b.Right::specialPrint(os);
        return os << ',' << b.w;
    }
};

int main() {
    Bottom b(1, 2, 3, 4);
    cout << b << endl; // ��������1,2,3,4
} ///:~
