//: C09:Dominance.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

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
    b.f(); // 调用Left::f()
} ///:~
