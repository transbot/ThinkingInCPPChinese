//: C06:partition_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示partition和stable_partition的功能和区别
// 对1-10的数字执行奇偶数分区
#include <iostream>
#include <vector>
#include <algorithm>

// 定义一个判断是否偶数的谓词函数
bool is_even(int x) {
    return x % 2 == 0;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 输出原始vector的内容 
    std::cout << "原始vector ：";
    for (int num : v) { std::cout << num << " "; }
    std::cout << std::endl;

    // 使用partition()
    std::vector<int> v1 = v;
    auto it1 = std::partition(v1.begin(), v1.end(), is_even);
    std::cout << "执行partition()后：";
    for (auto it = v1.begin(); it != it1; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "| ";
    for (auto it = it1; it != v1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 使用stable_partition()
    std::vector<int> v2 = v;
    auto it2 = std::stable_partition(v2.begin(), v2.end(), is_even);
    std::cout << "执行stable_partition()后：";
    for (auto it = v2.begin(); it != it2; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "| ";
    for (auto it = it2; it != v2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}