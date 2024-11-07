//: C06:nth_element_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示nth_element算法的效果
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 初始向量
    std::vector<int> v = {7, 2, 8, 4, 6, 3, 1};

    // 定义目标位置
    auto nth = v.begin() + 2;  // 第3个元素

    // 打印排序前的结果
    std::cout << "排序前的向量: ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // 使用默认比较谓词进行部分排序
    // 只保证第1个元素到第3个元素(nth)的有序，第4个元素到第5个元素不保证
    // 最后一个元素（即1）不在[first, last]的范围中
    std::nth_element(v.begin(), nth, v.begin()+4); // v.begin()+4定位到第5个元素

    // 打印部分排序后的结果
    std::cout << "排序后的向量: ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // 输出第3个元素
    std::cout << "排序后的第3个元素: " << *nth << std::endl;

    // 输出结果：
    // 排序前的向量: 7 2 8 4 6 3 1
    // 排序后的向量: 2 4 7 8 6 3 1
    // 排序后的第3个元素: 7

    return 0;
}