//: C07:VectorInsertAndErase.cpp {-bor}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 从vector的“中间”（而不是尾部）删除元素
//{L} Noisy
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "Noisy.h"
using namespace std;

int main() {
    vector<Noisy> v;
    v.reserve(11);
    cout << "已预留11个元素的空间" << endl;

    // 生成对象并填充vector
    generate_n(back_inserter(v), 10, NoisyGen());
    ostream_iterator<Noisy> out(cout, " ");
    cout << endl;
    copy(v.begin(), v.end(), out);

    // 在vector中间位置插入元素
    cout << "插入一个元素：" << endl;
    vector<Noisy>::iterator it = v.begin() + v.size() / 2; // 找到中间位置
    v.insert(it, Noisy());
    cout << endl;
    copy(v.begin(), v.end(), out);

    // 删除元素
    cout << "\n删除一个元素：" << endl;
    // 这里不能使用it先前的值，必须重新计算
    it = v.begin() + v.size() / 2;
    v.erase(it);
    cout << endl;
    copy(v.begin(), v.end(), out);
    cout << endl;
} ///:~
