//: C04:Format.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示各种格式化函数
#include <fstream>
#include <iostream>
#include "../require.h"
using namespace std;
#define D(A) T << #A << endl; A

int main() {
    ofstream T("format.out");
    assure(T);

    D(int i = 47;)
    D(float f = 2300114.414159;)
    const char* s = "还有更多吗？";

    D(T.setf(ios::unitbuf);)
    D(T.setf(ios::showbase);)
    D(T.setf(ios::uppercase | ios::showpos);)
    D(T << i << endl;) // 默认是十进制
    D(T.setf(ios::hex, ios::basefield);) // 十六进制
    D(T << i << endl;)
    D(T.setf(ios::oct, ios::basefield);) // 八进制
    D(T << i << endl;)
    D(T.unsetf(ios::showbase);)
    D(T.setf(ios::dec, ios::basefield);)
    D(T.setf(ios::left, ios::adjustfield);)
    D(T.fill('0');)
    D(T << "填充字符: " << T.fill() << endl;)
    D(T.width(10);)
    T << i << endl;
    D(T.setf(ios::right, ios::adjustfield);)
    D(T.width(10);)
    T << i << endl;
    D(T.setf(ios::internal, ios::adjustfield);)
    D(T.width(10);)
    T << i << endl;
    D(T << i << endl;) // 没有width(10)

    D(T.unsetf(ios::showpos);)
    D(T.setf(ios::showpoint);)
    D(T << "精度 = " << T.precision() << endl;)
    D(T.setf(ios::scientific, ios::floatfield);)
    D(T << endl << f << endl;)
    D(T.unsetf(ios::uppercase);)
    D(T << endl << f << endl;)
    D(T.setf(ios::fixed, ios::floatfield);)
    D(T << f << endl;)
    D(T.precision(20);)
    D(T << "精度 = " << T.precision() << endl;)
    D(T << endl << f << endl;)
    D(T.setf(ios::scientific, ios::floatfield);)
    D(T << endl << f << endl;)
    D(T.setf(ios::fixed, ios::floatfield);)
    D(T << f << endl;)

    D(T.width(10);)
    T << s << endl;
    D(T.width(40);)
    T << s << endl;
    D(T.setf(ios::left, ios::adjustfield);)
    D(T.width(40);)
    T << s << endl;
} ///:~
