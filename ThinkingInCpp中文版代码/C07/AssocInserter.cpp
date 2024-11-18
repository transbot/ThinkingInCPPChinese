//: C07:AssocInserter.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用一个insert_iterator，使fill_n()和generate_n()
// 能够与关联容器一起使用。
#include <iterator>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include "SimpleGenerators.h"

using namespace std;

int main() {
    set<int> s;
    // 在s中填充10个47
    // 由于set的去重特性，因为只留下一个47
    fill_n(inserter(s, s.begin()), 10, 47);

    // 再插入10个递增的值，从12开始
    generate_n(inserter(s, s.begin()), 10, IncrGen<int>(12));
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, "\n"));

    map<int, int> m;
    // 在m中填充10个键值对，即(90, 120)
    // m中的键应该是唯一的，因此重复的键90只会出现一次
    fill_n(inserter(m, m.begin()), 10, make_pair(90,120));

    // 再插入10个键值对，键从3开始递增，值从9开始递增（参见PairGen的定义）    
    generate_n(inserter(m, m.begin()), 10, PairGen<int, int>(3, 9));
    copy(m.begin(), m.end(), ostream_iterator<pair<int,int>>(cout, "\n"));
} ///:~
