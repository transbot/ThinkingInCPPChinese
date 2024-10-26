//: C05:StrTolower_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示三种字符串转换为小写的方法，请自行取消注释来实验
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <ranges>

int main() {
    std::string s("LOWER");

    // 使用lambda表达式，明确调用tolower函数
    // 具体的lambda表达式是[](char c) { return std::tolower(c); }
    std::transform(s.begin(), s.end(), s.begin(), [](char c) {
        return std::tolower(c);
    });
    std::cout << s << std::endl;

    // 使用C++20引入的std::ranges特性，编译命令是cl /EHsc StrTolower_CPP20.cpp /std:c++20
    // std::ranges::transform(s, s.begin(), [](char c) { return std::tolower(c); });
    // std::cout << s << std::endl;

    // 使用自定义函数对象
    // struct ToLower {
    //     char operator()(char c) const {
    //         return std::tolower(c);
    //     }
    // };    
    // std::transform(s.begin(), s.end(), s.begin(), ToLower());
    // std::cout << s << std::endl;

    return 0;
}