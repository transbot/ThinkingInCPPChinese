//: C06:set_union_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示set_union()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 3, 4};
    vector<int> b = {2, 2, 5, 6, 6};
    vector<int> result(a.size() + b.size());

    auto it = set_union(a.begin(), a.end(), b.begin(), b.end(), result.begin());

    // 打印结果
    for (auto it_result = result.begin(); it_result != it; ++it_result) {
        cout << *it_result << " ";
    }
    cout << endl;

    return 0;
}