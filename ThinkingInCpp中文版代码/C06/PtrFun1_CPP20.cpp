//: C06:PtrFun1_CPP20.cpp
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

int d[] = { 123, 94, 10, 314, 315 };
const int DSZ = sizeof d / sizeof *d;

// 该函数判断实参是不是偶数，是就返回true（1），不是则返回false（0）
bool isEven(int x) { return x % 2 == 0; }

void printResults(const vector<bool>& vb) {
    copy(vb.begin(), vb.end(), ostream_iterator<bool>(cout, " "));
    cout << endl;
}

int main() {
    // 使用lambda表达式
    vector<bool> vb1;
    transform(d, d + DSZ, back_inserter(vb1),
              [](int x) { return !isEven(x); });
    cout << "lambda表达式结果: ";
    printResults(vb1);

    // 使用std::function
    vector<bool> vb2;
    transform(d, d + DSZ, back_inserter(vb2),
              std::function<bool(int)>([](int x) { return !isEven(x); }));
    cout << "std::function 结果: ";
    printResults(vb2);

    // 使用std::bind
    vector<bool> vb3;
    transform(d, d + DSZ, back_inserter(vb3),
              std::bind(std::logical_not<bool>(), std::bind(isEven, std::placeholders::_1)));
    cout << "std::bind结果: ";
    printResults(vb3);

    return 0;
}