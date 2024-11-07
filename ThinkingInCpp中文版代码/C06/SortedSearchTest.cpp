//: C06:SortedSearchTest.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 测试在已排序范围内进行搜索。
// NString

// 测试在已排序范围中执行“查找”
#include <algorithm>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include "NString.h"
#include "PrintSequence.h"
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
    typedef vector<NString>::iterator sit;  // 定义迭代器类型
    const char* fname = "Test.txt";         // 默认文件名
    if(argc > 1) fname = argv[1];           // 如果提供了命令行实参，就使用提供的文件名
    ifstream in(fname);  // 打开文件
    assure(in, fname);   // 确保文件成功打开
    srand(time(0));      // 初始化随机数生成器
    cout.setf(ios::boolalpha);  // 设置输出格式为布尔值
    vector<NString> original;   // 这个向量用于存储原始数据
    copy(istream_iterator<string>(in),  // 从文件中读取数据
         istream_iterator<string>(), back_inserter(original)); // 将数据拷贝到原始向量中
    require(original.size() >= 4, "至少需要4个元素"); // 确保原始向量至少包含4个元素

    // 创建原始向量的拷贝v，并创建大小为原始向量的一半的向量v
    vector<NString> v(original.begin(), original.end()), w(original.size() / 2);

    sort(v.begin(), v.end());           // 对向量v进行排序
    print(v.begin(), v.end(), "sort");  // 打印排序后的向量v

    v = original;  // 恢复向量v为原始数据
    stable_sort(v.begin(), v.end());  // 对向量v进行稳定排序（保留原来的相对顺序）
    print(v.begin(), v.end(), "stable_sort");  // 打印稳定排序后的向量v

    v = original;  // 恢复向量v为原始数据
    sit it = v.begin(), it2;  // 定义迭代器it和it2
    // 将迭代器it移动到中间位置
    for(size_t i = 0; i < v.size() / 2; i++)
        ++it;
    partial_sort(v.begin(), it, v.end());  // 对向量v的前半部分进行部分排序
    cout << "middle = " << *it << endl;    // 输出中间位置的元素
    print(v.begin(), v.end(), "partial_sort");  // 打印部分排序后的向量v

    v = original;  // 恢复向量v为原始数据
    // 将迭代器it移动到四分之一位置
    it = v.begin();
    for(size_t i = 0; i < v.size() / 4; i++)
        ++it;

    // 源范围中的元素少于目标范围
    // 对向量v的前四分之一部分进行部分排序并拷贝到向量w
    partial_sort_copy(v.begin(), it, w.begin(), w.end());
    print(w.begin(), w.end(), "partial_sort_copy");   // 打印部分排序并拷贝后的向量w

    // 目标范围空间不足
    // 对向量v的全部内容进行部分排序并拷贝到向量w
    partial_sort_copy(v.begin(), v.end(), w.begin(), w.end());
    print(w.begin(), w.end(), "w partial_sort_copy");  // 打印部分排序并拷贝后的向量w

    // 验证在整个过程中，向量v保持不变
    assert(v == original);

    // 对向量v进行部分排序，使得*it成为第n个最小的元素
    nth_element(v.begin(), it, v.end());
    cout << "The nth_element = " << *it << endl;  // 输出第n个最小的元素
    print(v.begin(), v.end(), "nth_element");     // 打印部分排序后的向量v

    string f = original[rand() % original.size()];  // 随机选择一个元素f
    // 在向量v中进行二叉查找并输出结果
    cout << "二叉查找: "
         << binary_search(v.begin(), v.end(), f) << endl;

    sort(v.begin(), v.end());  // 对向量v进行排序
    it = lower_bound(v.begin(), v.end(), f);   // 查找第一个不小于f的元素的位置
    it2 = upper_bound(v.begin(), v.end(), f);  // 查找第一个大于f的元素的位置
    print(it, it2, "找到的范围");  // 打印找到的范围

    pair<sit, sit> ip = equal_range(v.begin(), v.end(), f);  // 查找f的等值范围
    print(ip.first, ip.second, "equal_range");               // 打印等值范围
} ///:~