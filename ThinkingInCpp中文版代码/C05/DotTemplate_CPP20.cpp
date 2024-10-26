//: C05:DotTemplate_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示如何用C++20的Concepts特性修改原示例程序
// 编译命令：cl /EHsc DotTemplate_CPP20.cpp /std:c++20
#include <bitset>
#include <cstddef>
#include <iostream>
#include <string>
#include <concepts>
#include <charconv>

// 定义一个概念，确保charT是一个字符类型
template<typename T>
concept CharType = std::is_same_v<T, char> || std::is_same_v<T, wchar_t>;

template<CharType charT, size_t N>
std::basic_string<charT> bitsetToString(const std::bitset<N>& bs) {
    return bs.to_string();
}

int main() {
    std::bitset<10> bs;
    bs.set(1);
    bs.set(5);
    std::cout << bs << std::endl; // 输出：0000100010
    std::string s = bitsetToString<char>(bs);
    std::cout << s << std::endl;  // 输出：0000100010
}