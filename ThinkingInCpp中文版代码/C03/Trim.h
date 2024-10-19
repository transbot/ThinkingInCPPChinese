//: C03:Trim.h
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 该通用工具用于去除字符串两端的空白字符
#ifndef TRIM_H
#define TRIM_H
#include <string>
#include <cstddef>

inline std::string trim(const std::string& s) {
    if(s.length() == 0)
        return s;
    std::size_t beg = s.find_first_not_of(" \a\b\f\n\r\t\v");
    std::size_t end = s.find_last_not_of(" \a\b\f\n\r\t\v");
    if(beg == std::string::npos) // 全是空白字符，没有非空白字符，因此全部去除
        return "";
    return std::string(s, beg, end - beg + 1); // 构造新字符串并返回
}
#endif // TRIM_H ///:~
