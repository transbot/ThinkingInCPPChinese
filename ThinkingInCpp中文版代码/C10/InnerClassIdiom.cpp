//: C10:InnerClassIdiom.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

//: C10:InnerClassIdiom.cpp
// “内部类”惯用法示例
#include <iostream>
#include <string>
using namespace std;

class Poingable { // 定义一个接口
public:
    virtual void poing() = 0; // 纯虚函数
};

void callPoing(Poingable& p) { // 使用接口
    p.poing();
}

class Bingable { // 定义另一个接口
public:
    virtual void bing() = 0; // 纯虚函数
};

void callBing(Bingable& b) { // 使用接口
    b.bing();
}

class Outer { // 外部类
private:
    string name;  // 私有数据成员
    class Inner1; // 定义第一个内部类
    friend class Outer::Inner1; // 内部类是外部类的友元
    class Inner1 : public Poingable { // 实现Poingable接口
    private:
        Outer* parent; // 指向外部类的指针
    public:
        Inner1(Outer* p) : parent(p) {} // 构造函数初始化指针
        void poing() {
            cout << "poing called for " << parent->name
                 << endl; // 访问外部类的数据
        }
    } inner1; // 创建内部类实例

    class Inner2; // 定义第二个内部类
    friend class Outer::Inner2; // 内部类是外部类的友元
    class Inner2 : public Bingable { // 实现Bingable接口
    private:
        Outer* parent; // 指向外部类的指针
    public:
        Inner2(Outer* p) : parent(p) {} // 构造函数初始化指针
        void bing() {
            cout << "bing called for " << parent->name
                 << endl; // 访问外部类的数据
        }
    } inner2; // 创建内部类实例

public:
    // 初始化外部类和内部类实例
    Outer(const string& nm) : name(nm), inner1(this), inner2(this) {} 
    // 返回内部类实现的接口的引用
    operator Poingable&() { return inner1; }
    operator Bingable&() { return inner2; }
};

int main() {
    Outer x("Ping Pong");
    // 模拟向上转型为多个基类型：
    callPoing(x); // 调用x的Poingable接口
    callBing(x);  // 调用x的Bingable接口
} ///:~
