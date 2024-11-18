//: C07:UniqueList.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 测试list的unique()函数
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int a[] = { 1, 3, 1, 4, 1, 5, 1, 6, 1 };
const int ASZ = sizeof a / sizeof *a;

int main() {
    // 用于输出
    ostream_iterator<int> out(cout, " ");
    list<int> li(a, a + ASZ);

    li.unique();
    // 哦豁！没有移除重复项
    copy(li.begin(), li.end(), out);
    cout << endl;

    // 必须先排序
    li.sort();
    copy(li.begin(), li.end(), out);
    cout << endl;

    // 现在unique()就会起作用了
    li.unique();
    copy(li.begin(), li.end(), out);
    cout << endl;
} ///:~
