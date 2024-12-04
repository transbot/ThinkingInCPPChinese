//: C09:VirtualBase3.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示流插入符的正确实现
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
    cout << b << endl; // 输出结果：1,2,3,4
} ///:~
