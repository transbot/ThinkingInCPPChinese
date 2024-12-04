//: C09:Offset.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示多重继承时子对象的布局
#include <iostream>
using namespace std;

// 以下三个类均包含一个int成员，假定int大小4，
// 那么A和B的大小均为4，而C的大小为12。
class A { int x; };
class B { int y; };
class C : public A, public B { int z; };

int main() {
    // 输出三个类的大小
    cout << "sizeof(A) == " << sizeof(A) << endl;
    cout << "sizeof(B) == " << sizeof(B) << endl;
    cout << "sizeof(C) == " << sizeof(C) << endl;

    C c;
    cout << "&c == " << &c << endl; // 输出对象c的地址
    A* ap = &c; // 将对象c的地址转换为A类型的指针
    B* bp = &c; // 将对象c的地址转换为B类型的指针

    // 输出刚才两个指针的地址
    cout << "ap == " << static_cast<void*>(ap) << endl; 
    cout << "bp == " << static_cast<void*>(bp) << endl;

    C* cp = static_cast<C*>(bp); // 将B类型的指针bp转换回C类型的指针cp
    cout << "cp == " << static_cast<void*>(cp) << endl; // 输出指针cp的地址
    // 判断B类型指针bp是否等于C类型指针cp
    cout << "bp == cp? " << boolalpha << (bp == cp) << endl;
    cp = 0;  // 现代C++应将0改为nulptr
    bp = cp; // 将C类型指针cp转换为B类型指针bp
    cout << bp << endl; // 输出指针bp的地址
} /* 输出结果（MSVC编译器）:
sizeof(A) == 4
sizeof(B) == 4
sizeof(C) == 12
&c == 00AFF800
ap == 00AFF800
bp == 00AFF804
cp == 00AFF800
bp == cp? true
00000000
*/ ///:~
