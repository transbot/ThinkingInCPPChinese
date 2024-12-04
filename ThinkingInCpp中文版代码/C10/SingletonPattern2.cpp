//: C10:SingletonPattern2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// Meyers’ Singleton
#include <iostream>
using namespace std;

class Singleton {
    int i;
    Singleton(int x) : i(x) { }  // 私有构造函数
    void operator=(Singleton&);  // 不允许赋值
    Singleton(const Singleton&); // 不允许拷贝构造
public:
    static Singleton& instance() {
        static Singleton s(47);
        return s;
    }
    int getValue() { return i; }    // 获取值
    void setValue(int x) { i = x; } // 设置值
};

int main() {
    Singleton& s = Singleton::instance();
    cout << s.getValue() << endl;
    Singleton& s2 = Singleton::instance();
    s2.setValue(9);
    cout << s.getValue() << endl;
} ///:~
