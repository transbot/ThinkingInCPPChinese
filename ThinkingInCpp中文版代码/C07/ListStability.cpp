//: C07:ListStability.cpp {-bor}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// list中的元素不会四处移动
//{L} Noisy
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include "Noisy.h"
using namespace std;

int main() {
    list<Noisy> l;
    ostream_iterator<Noisy> out(cout, " ");
    generate_n(back_inserter(l), 25, NoisyGen());
    cout << "\n 打印list：" << endl;
    copy(l.begin(), l.end(), out);
    cout << "\n 反转list：" << endl;
    l.reverse();
    copy(l.begin(), l.end(), out);
    cout << "\n 排序list：" << endl;
    l.sort();
    copy(l.begin(), l.end(), out);
    cout << "\n 交换两个元素：" << endl;
    list<Noisy>::iterator it1, it2;
    it1 = it2 = l.begin();
    ++it2;
    swap(*it1, *it2);
    cout << endl;
    copy(l.begin(), l.end(), out);
    cout << "\n 使用泛型reverse()函数：" << endl;
    reverse(l.begin(), l.end());
    cout << endl;
    copy(l.begin(), l.end(), out);
    cout << "\n 清理" << endl;
} ///:~
