//: C07:Valarray1.cpp {-bor}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示valarray的基本功能
#include "PrintValarray.h"
using namespace std;

double f(double x) {
    return 2.0 * x - 1.0;
}

int main() {
    double n[] = { 1.0, 2.0, 3.0, 4.0 };
    valarray<double> v(n, sizeof n / sizeof n[0]);
    print("v", v);

    valarray<double> sh(v.shift(1)); // 正数左移位，负数右移位
    print("左移1位", sh);

    valarray<double> acc(v + sh);
    print("求和", acc);

    valarray<double> trig(sin(v) + cos(acc));
    print("三角函数运算", trig);

    valarray<double> p(pow(v, 3.0));
    print("三次方", p);

    valarray<double> app(v.apply(f)); // 将f函数应用于v的每个元素
    print("f(v)", app);

    valarray<bool> eq(v == app); // 判断v和app是否相等
    print("v == app吗?", eq);

    double x = v.min(); // v的最小元素
    double y = v.max(); // v的最大元素
    double z = v.sum(); // v中所有元素之和
    cout << "x（最小） = " << x << ", y（最大） = " << y << ", z（总和） = " << z << endl;

    return 0;
} ///:~
