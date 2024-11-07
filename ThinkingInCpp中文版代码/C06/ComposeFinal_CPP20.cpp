//: C06:ComposeFinal_CPP20.cpp {-edg}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 避免创建composer，直接使用lambda表达式
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "NumStringGen.h"
using namespace std;



int main() {
    const int SZ = 9;      // 准备创建并转换9个字符串
    vector<string> vs(SZ); // 用随机数字字符串填充
    generate(vs.begin(), vs.end(), NumStringGen());
    copy(vs.begin(), vs.end(),
         ostream_iterator<string>(cout, "\t"));
    cout << endl;
    vector<double> vd;

    // 原书程序使用ptr_fun()和mem_fun_ref已弃用
    // transform(vs.begin(), vs.end(), back_inserter(vd),
    //           compose(ptr_fun(atof), mem_fun_ref(&string::c_str)));

    // 改为使用lambda表达式，并用stod替换atof
    transform(vs.begin(), vs.end(), std::back_inserter(vd),
                   [](const std::string& str) { return std::stod(str); });        
    
    copy(vd.begin(), vd.end(),
         ostream_iterator<double>(cout, "\t"));
    cout << endl;
} ///:~
