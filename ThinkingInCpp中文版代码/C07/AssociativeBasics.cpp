//: C07:AssociativeBasics.cpp {-bor}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// set和map的基本操作
#include <cstddef>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include "Noisy.h"
using namespace std;

int main() {
    Noisy na[7];
    // 通过构造函数将数组na中的元素添加到set
    set<Noisy> ns(na, na + sizeof na / sizeof(Noisy));
    Noisy n;
    ns.insert(n); // 将单个Noisy类型的元素n插入set
    cout << endl;

    // 使用set的成员函数
    cout << "ns.count(n)= " << ns.count(n) << endl; // 检查n在set中出现的次数
    if(ns.find(n) != ns.end()) // 查找n是否存在于set中
        cout << "在ns中发现了n(" << n << ")" << endl;

    // 打印set中的所有元素
    copy(ns.begin(), ns.end(),
         ostream_iterator<Noisy>(cout, " "));
    cout << endl;
    cout << "\n-----------" << endl;

    // 使用map
    map<int, Noisy> nm;
    for(int i = 0; i < 10; i++)
        nm[i]; // 自动创建键值对，键为i，值为默认构造的Noisy对象
    cout << "\n-----------" << endl;

    // 打印map中的所有键值对
    for(size_t j = 0; j < nm.size(); j++)
        cout << "nm[" << j << "] = " << nm[j] << endl;
    cout << "\n-----------" << endl;

    // 插入键值对，键为10，值为n
    nm[10] = n;
    cout << "\n-----------" << endl;

    // 插入键值对，键为47，值为n
    nm.insert(make_pair(47, n));
    cout << "\n-----------" << endl;

    // 检查键10和11在map中是否存在
    cout << "\n nm.count(10)= " << nm.count(10) << endl;
    cout << "nm.count(11)= " << nm.count(11) << endl;

    // 查找键6对应的值
    map<int, Noisy>::iterator it = nm.find(6);
    if(it != nm.end())
        cout << " nm的位置6中的值是:" << (*it).second << endl;

    // 打印map中的所有键值对
    for(it = nm.begin(); it != nm.end(); it++)
        cout << (*it).first << ":" << (*it).second << ", ";
    cout << "\n-----------" << endl;
    return 0;
} ///:~