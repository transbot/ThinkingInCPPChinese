//: C09:Vendor.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 供应商提供的类的头文件
// 我们只能拿到这个，以及编译后的Vendor.obj
#ifndef VENDOR_H
#define VENDOR_H

class Vendor {
public:
    virtual void v() const;
    void f() const; // 可能希望它是虚的...
    ~Vendor();      // 哎呀！不是虚的！
};

class Vendor1 : public Vendor {
public:
    void v() const;
    void f() const;
    ~Vendor1();
};

void A(const Vendor&);
void B(const Vendor&);
// 等等...
#endif // VENDOR_H ///:~
