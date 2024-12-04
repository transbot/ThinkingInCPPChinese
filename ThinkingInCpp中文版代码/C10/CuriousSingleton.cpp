//: C10:CuriousSingleton.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 将类的“单例性”与其实现分离（几乎）
#include <iostream>
using namespace std;

template<class T>
class Singleton {
    Singleton(const Singleton&); // 不允许拷贝构造
    Singleton& operator=(const Singleton&); // 不允许赋值
protected:
    Singleton() {} // 受保护构造函数
    virtual ~Singleton() {} // 虚析构函数
public:
    static T& instance() {
        static T theInstance;
        return theInstance;
    }
};

// 一个示例类，转换为单例
class MyClass : public Singleton<MyClass> {
    int x;
protected:
    friend class Singleton<MyClass>; // 将Singleton<MyClass>声明为友元
    MyClass() { x = 0; } // 私有构造函数
public:
    void setValue(int n) { x = n; }    // 设置值
    int getValue() const { return x; } // 获取值
};

int main() {
    MyClass& m = MyClass::instance();
    cout << m.getValue() << endl;
    m.setValue(1);
    cout << m.getValue() << endl;
} ///:~
