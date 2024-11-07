//: C06:SearchReplace_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// STL查找和替换算法
#include <algorithm>
#include <functional>
#include <vector>
#include "PrintSequence.h" // 假设这是一个自定义的头文件，用于打印序列
using namespace std;

// 自定义谓词：检查两个整数是否满足j == i + 1
struct PlusOne { 
    bool operator()(int i, int j) { return j == i + 1; } 
};

// 自定义谓词：检查两个整数的乘积是否大于给定值
class MulMoreThan { 
    int value;
public: 
    MulMoreThan(int val) : value(val) {} 
    bool operator()(int v, int m) { 
        return v * m > value; 
    } 
};

int main() { 
    // 初始化一个整数数组
    int a[] = { 1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 8, 8, 8, 8, 11, 11, 11, 11, 11 }; 
    const int ASZ = sizeof a / sizeof *a; // 计算数组的大小
    vector<int> v(a, a + ASZ);            // 将数组转换为vector
    print(v.begin(), v.end(), "v", " ");  // 打印向量v的内容
    
    // 使用find查找值4
    vector<int>::iterator it = find(v.begin(), v.end(), 4); 
    cout << "find: " << *it << endl; 
    
    // 使用find_if查找大于8的值
    // 现代C++应使用lambda表达式替换bind2nd：
    // it = find_if(v.begin(), v.end(), bind2nd(greater<int>(), 8)); 
    it = find_if(v.begin(), v.end(), [](int x) { return x > 8; });
    // 或者：
    // it = find_if(v.begin(), v.end(), [&](int x) { return greater<int>()(x, 8); });
    cout << "find_if: " << *it << endl; 
    
    // 使用adjacent_find查找相邻的重复元素
    it = adjacent_find(v.begin(), v.end()); 
    while(it != v.end()) { 
        cout << "adjacent_find: " << *it << ", " << *(it + 1) << endl; 
        it = adjacent_find(it + 1, v.end()); 
    } 
    
    // 使用adjacent_find和自定义谓词PlusOne查找相邻元素满足j == i + 1的情况
    it = adjacent_find(v.begin(), v.end(), PlusOne()); 
    while(it != v.end()) { 
        cout << "adjacent_find PlusOne: " << *it << ", " << *(it + 1) << endl; 
        it = adjacent_find(it + 1, v.end(), PlusOne()); 
    } 
    
    // 初始化另一个整数数组b
    int b[] = { 8, 11 }; 
    const int BSZ = sizeof b / sizeof *b; // 计算数组b的大小
    print(b, b + BSZ, "b", " ");          // 打印数组b的内容
    
    // 使用find_first_of查找向量v中第一个也在数组b中的元素
    it = find_first_of(v.begin(), v.end(), b, b + BSZ); 
    print(it, it + BSZ, "find_first_of", " "); 
    
    // 使用find_first_of和自定义谓词PlusOne查找向量v中第一个符合条件的元素：
    // 该元素与数组b中的元素满足j == i + 1。
    it = find_first_of(v.begin(), v.end(), b, b + BSZ, PlusOne()); 
    print(it, it + BSZ, "find_first_of PlusOne", " "); 
    
    // 使用search查找数组b在向量v中的子序列
    it = search(v.begin(), v.end(), b, b + BSZ); 
    print(it, it + BSZ, "search", " "); 
    
    // 初始化另一个整数数组c
    int c[] = { 5, 6, 7 }; 
    const int CSZ = sizeof c / sizeof *c; // 计算数组c的大小
    print(c, c + CSZ, "c", " ");          // 打印数组c的内容

    // 使用search和自定义谓词PlusOne查找数组c在向量v中的子序列，
    // 要求满足j == i + 1。
    it = search(v.begin(), v.end(), c, c + CSZ, PlusOne()); 
    print(it, it + CSZ, "search PlusOne", " "); 
    
    // 初始化另一个整数数组d
    int d[] = { 11, 11, 11 }; 
    const int DSZ = sizeof d / sizeof *d; // 计算数组d的大小
    print(d, d + DSZ, "d", " ");          // 打印数组d的内容
    
    // 使用find_end查找数组d在向量v中的最后一次出现
    it = find_end(v.begin(), v.end(), d, d + DSZ); 
    print(it, v.end(), "find_end", " ");  // 从it开始打印v的剩余部分
    
    // 初始化另一个整数数组e
    int e[] = { 9, 9 }; 
    print(e, e + 2, "e", " "); // 打印数组e的内容
    
    // 使用find_end和自定义谓词PlusOne查找数组d在向量v中的最后一次出现，
    // 要求满足j == i + 1。
    it = find_end(v.begin(), v.end(), e, e + 2, PlusOne()); 
    print(it, v.end(), "find_end PlusOne", " "); 
    
    // 使用search_n查找在向量v中连续出现3次的值7
    it = search_n(v.begin(), v.end(), 3, 7); 
    print(it, it + 3, "search_n 3, 7", " "); 
    
    // 使用search_n和自定义谓词MulMoreThan在向量v中查找连续6个值，
    // 当它们各自乘以15时，结果都大于100。    
    it = search_n(v.begin(), v.end(), 6, 15, MulMoreThan(100)); 
    print(it, it + 6, "search_n 6, 15, MulMoreThan(100)", " "); 
    
    // 使用min_element查找向量v中的最小值
    cout << "min_element: " << *min_element(v.begin(), v.end()) << endl; 
    
    // 使用max_element查找向量v中的最大值
    cout << "max_element: " << *max_element(v.begin(), v.end()) << endl; 
    
    // 使用replace_copy将向量v中的所有8替换为47，并将结果的拷贝存储到向量v2中
    vector<int> v2; 
    replace_copy(v.begin(), v.end(), back_inserter(v2), 8, 47); 
    print(v2.begin(), v2.end(), "replace_copy 8 -> 47", " "); 
    
    // 使用replace_if将向量v中所有大于等于7的值替换为-1
    // 现代C++应使用lambda表达式替换bind2nd：
    // replace_if(v.begin(), v.end(), bind2nd(greater_equal<int>(), 7), -1); 
    replace_if(v.begin(), v.end(), [&](int x) { return greater_equal<int>()(x, 7); }, -1);
    // 或者：
    // replace_if(v.begin(), v.end(), [&](int x) { return greater_equal<int>()(x, 7); }, -1);
    print(v.begin(), v.end(), "replace_if >= 7 -> -1", " "); 
} ///:~