//: C06:adjacent_find_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示查找“相邻元素”的算法
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 2, 4, 5, 5};
    // 输出原始vector的内容 
    std::cout << "原始vector ：";
    for (int num : numbers) { std::cout << num << " "; }
    std::cout << std::endl;

    // 查找相邻的两个相等元素（使用默认的==操作符）
    auto it = std::adjacent_find(numbers.begin(), numbers.end());
    if (it != numbers.end()) {
        std::cout << "找到了相邻的两个相等元素：" << *it << std::endl;
    }

    // 查找相邻的两个元素，其中第一个元素小于第二个元素
    auto it2 = std::adjacent_find(numbers.begin(), numbers.end(), [](int x, int y) { return x < y; });
    if (it2 != numbers.end()) {
        std::cout << "找到了相邻的两个元素，第一个小于第二个：" << *it2 << " " << *(it2 + 1) << std::endl;
    }

    return 0;
}