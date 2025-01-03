//: C10:FibonacciGeneratorTest.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
#include "FibonacciGenerator.h"
using namespace std;

int main() {
    FibonacciGenerator f;
    for(int i = 0; i < 20; i++) // 生成并输出前20个斐波那契数
        cout << f.count() << ": " << f() << endl;
} ///:~
