//: C10:SingletonPattern.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include <iostream>
using namespace std;

class Singleton {
    static Singleton s;
    int i;
    Singleton(int x) : i(x) { } // 私有构造函数
    Singleton& operator=(Singleton&); // 不允许赋值
    Singleton(const Singleton&); // 不允许拷贝构造
public:
    static Singleton& instance() { return s; } // 获取唯一实例，注意返回的是引用
    int getValue() { return i; } // 获取值
    void setValue(int x) { i = x; } // 设置值
};

Singleton Singleton::s(47); // 在类的外部静态实例化类的成员变量s

int main() {
    // 调用静态成员函数获取Singleton类的唯一实例
    Singleton& s = Singleton::instance(); 

    // 调用getValue方法获取并输出实例的初始值，应输出47
    cout << s.getValue() << endl; 

    // 获取Singleton类的同一个实例
    Singleton& s2 = Singleton::instance(); 
    
    s2.setValue(9); // 通过s2这个引用，将实例的值更改为9
    cout << s.getValue() << endl; // 应输出9
} ///:~
