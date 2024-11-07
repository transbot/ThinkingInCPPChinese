//: C06:PtrFun1.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 用ptr_fun()来包装一元函数
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int d[] = { 123, 94, 10, 314, 315 };
const int DSZ = sizeof d / sizeof *d;

// 该函数判断实参是不是偶数，是就返回true（1），不是则返回false（0）
bool isEven(int x) { return x % 2 == 0; }

int main() {
    vector<bool> vb;
    transform(d, d + DSZ, back_inserter(vb),
              not1(ptr_fun(isEven)));
    copy(vb.begin(), vb.end(),
         ostream_iterator<bool>(cout, " "));
    cout << endl; 
    // 输出: 1 0 0 0 1
} ///:~
