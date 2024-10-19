//: C04:Manips.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用操纵元（manipulator）重写Format.cpp
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    ofstream trc("trace.out");
    int i = 47;
    float f = 2300114.414159;
    char* s = "还有更多吗？";

    trc << setiosflags(ios::unitbuf | ios::showbase | ios::uppercase | ios::showpos);

    trc << i << endl;
    trc << hex << i << endl
        << oct << i << endl;

    trc.setf(ios::left, ios::adjustfield);
    trc << resetiosflags(ios::showbase)
        << dec << setfill('0');

    trc << "填充字符: " << trc.fill() << endl;
    trc << setw(10) << i << endl;

    trc.setf(ios::right, ios::adjustfield);
    trc << setw(10) << i << endl;

    trc.setf(ios::internal, ios::adjustfield);
    trc << setw(10) << i << endl;

    trc << i << endl; // Without setw(10)

    trc << resetiosflags(ios::showpos)
        << setiosflags(ios::showpoint)
        << "精度 = " << trc.precision() << endl;

    trc.setf(ios::scientific, ios::floatfield);
    trc << f << resetiosflags(ios::uppercase) << endl;

    trc.setf(ios::fixed, ios::floatfield);
    trc << f << endl;

    trc << f << endl;

    trc << setprecision(20);
    trc << "精度 = " << trc.precision() << endl;
    trc << f << endl;

    trc.setf(ios::scientific, ios::floatfield);
    trc << f << endl;

    trc.setf(ios::fixed, ios::floatfield);
    trc << f << endl;

    trc << setw(10) << s << endl;
    trc << setw(40) << s << endl;

    trc.setf(ios::left, ios::adjustfield);
    trc << setw(40) << s << endl;
} ///:~
