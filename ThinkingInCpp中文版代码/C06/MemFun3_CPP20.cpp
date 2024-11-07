//: C06:MemFun3_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用现代C++特性进行字符串到浮点数的转换
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "NumStringGen.h"
using namespace std;

int main() {
    const int SZ = 9;  // 准备生成并转换9个浮点数
    vector<string> vs(SZ);
    
    // 用随机数字字符串来填充vs向量
    srand(time(0));                                 // 初始化随机数种子
    generate(vs.begin(), vs.end(), NumStringGen()); // 生成随机数字字符串

    // 输出生成的随机数字符串
    copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, "\t"));
    cout << endl;

    // 使用lambda表达式将字符串转换为C风格字符串
    vector<const char*> vcp(SZ);
    transform(vs.begin(), vs.end(), vcp.begin(), [](const string& s) { return s.c_str(); });

    // 使用lambda表达式将C风格字符串转换为双精度浮点数
    // 原书使用的是atof()。虽然它是一个常用的C库函数，但在现代C++中，
    // 更推荐使用std::stod来进行字符串到浮点数的转换。
    // std::stod是C++11引入的标准库函数，它提供了更安全和更方便的转换方式。
    vector<double> vd;
    transform(vcp.begin(), vcp.end(), back_inserter(vd), [](const char* s) { return std::stod(s); });

    // 设置输出格式
    cout.precision(4);
    cout.setf(ios::showpoint);

    // 输出转换后的浮点数
    copy(vd.begin(), vd.end(), ostream_iterator<double>(cout, "\t"));
    cout << endl;

    return 0;
}