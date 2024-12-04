//: C09:Interfaces.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 多接口继承
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// 定义Printable接口类
class Printable {
public:
    virtual ~Printable() {}  // 虚析构函数，确保派生类的析构函数被正确调用
    virtual void print(ostream&) const = 0;  // 纯虚函数，定义打印方法
};

// 定义Intable接口类
class Intable {
public:
    virtual ~Intable() {}  // 虚析构函数，确保派生类的析构函数被正确调用
    virtual int toInt() const = 0;  // 纯虚函数，定义转换为整数的方法
};

// 定义Stringable接口类
class Stringable {
public:
    virtual ~Stringable() {}  // 虚析构函数，确保派生类的析构函数被正确调用
    virtual string toString() const = 0;  // 纯虚函数，定义转换为字符串的方法
};

// 定义Able类，同时继承 Printable、Intable 和 Stringable 接口
class Able : public Printable, public Intable, public Stringable {
    int myData;  // 成员变量，存储数据
public:
    Able(int x) { myData = x; }  // 构造函数，初始化成员变量

    // 实现Printable 接口的print方法
    void print(ostream& os) const { 
        os << myData;  // 将数据输出到指定的流
    }

    // 实现Intable接口的toInt方法
    int toInt() const { 
        return myData;  // 返回存储的数据
    }

    // 实现Stringable接口的toString方法
    string toString() const {
        ostringstream os;  // 创建字符串流对象
        os << myData;      // 将数据写入字符串流
        return os.str();   // 返回字符串流的内容
    }
};

// 测试Printable接口的方法
void testPrintable(const Printable& p) {
    p.print(cout); // 调用Printable接口的print方法，将数据输出到标准输出
    cout << endl;  // 插入换行符
}

// 测试Intable接口的方法
void testIntable(const Intable& n) {
    // 调用Intable接口的toInt方法，将结果加1后输出
    cout << n.toInt() + 1 << endl;  
}

// 测试Stringable接口的方法
void testStringable(const Stringable& s) {
    // 调用Stringable接口的toString方法，将结果拼接后输出
    cout << s.toString() + "th" << endl; 
}

int main() {
    Able a(7);  // 创建Able类的对象，初始化数据为7

    // 测试Printable接口
    testPrintable(a);   // 输出：7

    // 测试Intable接口
    testIntable(a);     // 输出：8

    // 测试Stringable接口
    testStringable(a);  // 输出：7th

    return 0;
}
