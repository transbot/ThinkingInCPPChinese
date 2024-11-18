//: C08:VoidRTTI.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// RTTI与void 指针
//!#include <iostream>
#include <typeinfo>
using namespace std;

class Stimpy {
public:
    virtual void happy() {}
    virtual void joy() {}
    virtual ~Stimpy() {}
};

int main() {
    void* v = new Stimpy;
    // 错误：
    //! Stimpy* s = dynamic_cast<Stimpy*>(v);
    // 错误：
    //! cout << typeid(*v).name() << endl;
} ///:~
