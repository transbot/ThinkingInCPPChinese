//: C06:NumericTest.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>
#include <numeric>
#include "PrintSequence.h"
using namespace std;

int main() {
    int a[] = { 1, 1, 2, 2, 3, 5, 7, 9, 11, 13 };
    const int ASZ = sizeof a / sizeof a[0];
    print(a, a + ASZ, "a", " ");
    int r = accumulate(a, a + ASZ, 0);
    cout << "accumulate 1: " << r << endl;

    // 应该产生相同的结果
    r = accumulate(a, a + ASZ, 0, plus<int>());
    cout << "accumulate 2: " << r << endl;

    int b[] = { 1, 2, 3, 4, 1, 2, 3, 4, 1, 2 };
    print(b, b + sizeof b / sizeof b[0], "b", " ");

    r = inner_product(a, a + ASZ, b, 0);
    cout << "inner_product 1: " << r << endl;
    // 应该产生相同的结果
    r = inner_product(a, a + ASZ, b, 0, plus<int>(), multiplies<int>());
    cout << "inner_product 2: " << r << endl;

    int* it = partial_sum(a, a + ASZ, b);
    print(b, it, "partial_sum 1", " ");
    // 应该产生相同的结果
    it = partial_sum(a, a + ASZ, b, plus<int>());
    print(b, it, "partial_sum 2", " ");

    it = adjacent_difference(a, a + ASZ, b);
    print(b, it, "adjacent_difference 1", " ");
    // 应该产生相同的结果
    it = adjacent_difference(a, a + ASZ, b, minus<int>());
    print(b, it, "adjacent_difference 2", " ");
} ///:~
