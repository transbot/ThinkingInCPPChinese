//: C10:TemplateMethod.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 模板方法的简单演示
#include <iostream>
using namespace std;

// 应用程序框架类
class ApplicationFramework {
protected:
    // 需要在派生类中实现的自定义方法
    virtual void customize1() = 0;
    virtual void customize2() = 0;

public:
    // 模板方法，定义了算法的骨架
    void templateMethod() {
        for(int i = 0; i < 5; i++) {
            customize1(); // 调用第一个自定义方法
            customize2(); // 调用第二个自定义方法
        }
    }
};

// 创建一个新的“应用程序”，继承自应用程序框架
class MyApp : public ApplicationFramework {
protected:
    // 实现自定义方法customize1
    void customize1() { cout << "Hello "; }

    // 实现自定义方法customize2
    void customize2() { cout << "World!" << endl; }
};

int main() {
    MyApp app; // 创建MyApp对象
    app.templateMethod(); // 调用模板方法
} ///:~