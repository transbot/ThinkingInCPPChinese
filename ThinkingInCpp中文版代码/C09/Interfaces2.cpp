//: C09:Interfaces2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

//: C09:Interfaces2.cpp
// 通过模板实现隐式接口继承
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// 定义Able类，实现多个方法
class Able {
    int myData;  // 成员变量，存储数据
public:
    Able(int x) { myData = x; }  // 构造函数，初始化成员变量

    // 实现 print 方法，输出数据到指定的流
    void print(ostream& os) const { 
        os << myData;  // 将数据输出到指定的流
    }

    // 实现 toInt 方法，返回数据的整数值
    int toInt() const { 
        return myData;  // 返回存储的数据
    }

    // 实现toString方法，返回数据的字符串表示
    string toString() const {
        ostringstream os;  // 创建字符串流对象
        os << myData;      // 将数据写入字符串流
        return os.str();   // 返回字符串流的内容
    }
};

// 定义模板函数 testPrintable，测试Printable接口的方法
template<class Printable>
void testPrintable(const Printable& p) {
    p.print(cout);  // 调用Printable接口的print方法，将数据输出到标准输出
    cout << endl;   // 插入换行符
}

// 定义模板函数 testIntable，测试Intable接口的方法
template<class Intable>
void testIntable(const Intable& n) {
    cout << n.toInt() + 1 << endl;  // 调用Intable接口的 toInt方法，将结果加1后输出
}

// 定义模板函数 testStringable，测试Stringable接口的方法
template<class Stringable>
void testStringable(const Stringable& s) {
    cout << s.toString() + "th" << endl;  // 调用Stringable接口的toString方法，将结果拼接后输出
}

int main() {
    Able a(7);  // 创建Able类的对象，初始化数据为 7

    // 测试Printable接口
    testPrintable(a);  // 输出：7

    // 测试Intable接口
    testIntable(a);  // 输出：8

    // 测试 Stringable 接口
    testStringable(a);  // 输出：7th

    return 0;
}