//: C06:NString.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 一种“编号字符串”，跟踪记录其所含单词的出现次数
#ifndef NSTRING_H
#define NSTRING_H
#include <algorithm>
#include <iostream>
#include <string>
#include <utility> // 为了使用std::pair
#include <vector>

// 定义一个类型别名，用于存储字符串和出现次数的pair
typedef std::pair<std::string, int> psi;

// 仅基于第一个元素（字符串）进行比较
bool operator==(const psi& l, const psi& r) { 
    return l.first == r.first; 
}

class NString {
    std::string s;      // 存储的字符串
    int thisOccurrence; // 跟踪出现次数

    // 使用std::vector存储所有字符串及其出现次数
    typedef std::vector<psi> vp;

    // 该vector的迭代器
    typedef vp::iterator vpit;

    // 静态成员变量，用于记录所有字符串及其出现次数
    static vp words;

    // 将字符串添加到静态记录中
    void addString(const std::string& x) {
        psi p(x, 0);
        vpit it = std::find(words.begin(), words.end(), p);
        if (it != words.end()) {
            // 如果字符串已存在于记录中，就递增出现次数
            thisOccurrence = ++it->second;
        } else {
            // 如果字符串不存在于记录中，就将出现次数初始化为0并添加到记录中
            thisOccurrence = 0;
            words.push_back(p);
        }
    }

public:
    // 默认构造函数
    NString() : thisOccurrence(0) {}

    // 构造函数，接受一个std::string
    NString(const std::string& x) : s(x) { 
        addString(x); 
    }

    // 构造函数，接受C风格字符串
    NString(const char* x) : s(x) { 
        addString(x); 
    }

    // 输出操作符重载，用于打印NString对象
    friend std::ostream& operator<<(std::ostream& os, const NString& ns) {
        return os << ns.s << " [" << ns.thisOccurrence << "]";
    }

    // 比较操作符重载，用于排序，仅比较字符串部分，而不比较出现次数
    friend bool operator<(const NString& l, const NString& r) { 
        return l.s < r.s; 
    }

    // 比较操作符重载，用于相等性检查，仅比较字符串部分
    friend bool operator==(const NString& l, const NString& r) { 
        return l.s == r.s; 
    }

    // 比较操作符重载，用于greater<NString>排序（参见正文的解释），仅比较字符串部分
    friend bool operator>(const NString& l, const NString& r) { 
        return l.s > r.s; 
    }

    // 隐式转型为const std::string&，直接获取字符串部分
    operator const std::string&() const { 
        return s; 
    }
};

// 初始化静态成员变量。
// 由于NString::vp是一个模板，并且我们使用的是包含模型，
// 因此必须在这个头文件中进行。
NString::vp NString::words;
#endif // NSTRING_H ///:~