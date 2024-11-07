//: C06:MemFun3.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用mem_fun_ref()
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
    const int SZ = 9; // 准备生成并转换9个浮点数
    vector<string> vs(SZ);
    // 用随机数字字符串来填充vs向量
    srand(time(0));                                 // 初始化随机数种子
    generate(vs.begin(), vs.end(), NumStringGen()); // 生成随机数字字符串    
    copy(vs.begin(), vs.end(),
         ostream_iterator<string>(cout, "\t"));
    cout << endl;
    const char* vcp[SZ];
    transform(vs.begin(), vs.end(), vcp,
              mem_fun_ref(&string::c_str));
    vector<double> vd;
    transform(vcp, vcp + SZ, back_inserter(vd),
              std::atof);
    cout.precision(4);
    cout.setf(ios::showpoint);
    copy(vd.begin(), vd.end(),
         ostream_iterator<double>(cout, "\t"));
    cout << endl;
} ///:~