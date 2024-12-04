//: C09:VirtualBase.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 通过虚基类实现对同一个子对象的共享
#include <iostream>
using namespace std;

class Top { // 虚基类
protected:
    int x;  // 成员变量x
public:
    Top(int n) { x = n; }  // 构造函数，初始化x
    virtual ~Top() {}  // 虚析构函数，确保派生类的析构函数被正确调用
    friend ostream& operator<<(ostream& os, const Top& t) {
        return os << t.x;  // 重载<<操作符，输出x
    }
};

// 定义派生类Left，虚继承自Top
class Left : virtual public Top {
protected:
    int y;  // 成员变量y
public:
    Left(int m, int n) : Top(m) { y = n; }  // 构造函数，初始化基类Top和成员变量y
};

// 定义派生类Right，虚继承自Top
class Right : virtual public Top {
protected:
    int z;  // 成员变量 z
public:
    Right(int m, int n) : Top(m) { z = n; }  // 构造函数，初始化基类Top 和成员变量z
};

// 定义派生类 Bottom，多重继承自Left和Right
class Bottom : public Left, public Right {
    int w;  // 成员变量w
public:
    // 构造函数，初始化基类Top、Left和 Right，以及成员变量w
    Bottom(int i, int j, int k, int m) : Top(i), Left(0, j), Right(0, k) { w = m; }    

    // 重载<<操作符，输出所有成员变量
    friend ostream& operator<<(ostream& os, const Bottom& b) {
        return os << b.x << ',' << b.y << ',' << b.z << ',' << b.w;
    }
};

int main() {
    Bottom b(1, 2, 3, 4);  // 创建 Bottom类的对象b，初始化成员变量
    cout << "sizeof(b) == " << sizeof(b) << endl;  // 输出对象b的大小
    cout << "b == " << b << endl;  // 输出对象b的所有成员变量
    cout << "&b == " << static_cast<void*>(&b) << endl;  // 输出对象b的地址
    Top* p = static_cast<Top*>(&b);  // 将对象b的地址转换为Top类型的指针
    cout << "*p == " << *p << endl;  // 输出通过指针p访问的Top部分的x值
    cout << "p == " << static_cast<void*>(p) << endl;  // 输出指针p的地址
    // 使用dynamic_cast转换指针p的地址
    cout << "dynamic_cast<void*>(p) == " << dynamic_cast<void*>(p) << endl;  
}