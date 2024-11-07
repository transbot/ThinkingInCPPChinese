//: C06:PtrFun2_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示使用三种技术来替代过时的ptr_fun()，
// 它们都能“包装”一个函数。
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

double d[] = { 1.23, 91.370, 56.661, 23.230, 19.959, 1.0, 3.14159 };
const int DSZ = sizeof d / sizeof *d;

void printResults(const vector<double>& vd) {
    copy(vd.begin(), vd.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
}

int main() {
    // 使用Lambda表达式
    vector<double> vd1;
    transform(d, d + DSZ, back_inserter(vd1),
              [](double x) { return pow(x, 2.0); });
    cout << "Lambda表达式结果: ";
    printResults(vd1);

    // 使用std::function
    vector<double> vd2;
    transform(d, d + DSZ, back_inserter(vd2),
              std::function<double(double)>([](double x) { return pow(x, 2.0); }));
    cout << "std::function结果: ";
    printResults(vd2);

    // 使用std::bind
    vector<double> vd3;
    transform(d, d + DSZ, back_inserter(vd3),
        std::bind(static_cast<double(*)(double, double)>(pow), std::placeholders::_1, 2.0));
    cout << "std::bind结果: ";
    printResults(vd3);

    return 0;
}