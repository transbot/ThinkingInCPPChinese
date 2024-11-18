//: C07:RawStorageIterator.cpp {-bor}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示raw_storage_iterator的用法
//{L} Noisy
#include <iostream>
#include <iterator>
#include <algorithm>
#include "Noisy.h"
using namespace std;

int main() {
    const int QUANTITY = 10;
    // 创建原始存储并转换为目标类型
    Noisy* np = reinterpret_cast<Noisy*>(
        new char[QUANTITY * sizeof(Noisy)]);
    raw_storage_iterator<Noisy*, Noisy> rsi(np);
    for(int i = 0; i < QUANTITY; i++)
        *rsi++ = Noisy(); // 将对象放入存储中
    cout << endl;
    copy(np, np + QUANTITY,
         ostream_iterator<Noisy>(cout, " "));
    cout << endl;
    // 显式调用析构函数进行资源清理
    for(int j = 0; j < QUANTITY; j++)
        (&np[j])->~Noisy();
    // 释放原始存储
    delete reinterpret_cast<char*>(np);
} ///:~
