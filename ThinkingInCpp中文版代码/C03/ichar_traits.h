//: C03:ichar_traits.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 创建自定义的字符trait
#ifndef ICHAR_TRAITS_H
#define ICHAR_TRAITS_H
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <ostream>
#include <string>

using std::allocator;
using std::basic_string;
using std::char_traits;
using std::ostream;
using std::size_t;
using std::string;
using std::toupper;
using std::tolower;

struct ichar_traits : char_traits<char> {
    // 我们只更改字符比较函数
    static bool eq(char c1st, char c2nd) {
        return toupper(c1st) == toupper(c2nd);
    }
    static bool ne(char c1st, char c2nd) {
        return !eq(c1st, c2nd);
    }
    static bool lt(char c1st, char c2nd) {
        return toupper(c1st) < toupper(c2nd);
    }
    static int compare(const char* str1, const char* str2, size_t n) {
        for(size_t i = 0; i < n; ++i) {
            if(str1 == 0)
                return -1;
            else if(str2 == 0)
                return 1;
            else if(tolower(*str1) < tolower(*str2))
                return -1;
            else if(tolower(*str1) > tolower(*str2))
                return 1;
            assert(tolower(*str1) == tolower(*str2));
            ++str1; ++str2; // Compare the other chars
        }
        return 0;
    }
    static const char*
    find(const char* s1, size_t n, char c) {
        while(n-- > 0)
            if(toupper(*s1) == toupper(c))
                return s1;
            else
                ++s1;
        return 0;
    }
};

typedef basic_string<char, ichar_traits> istring;

inline ostream& operator<<(ostream& os, const istring& s) {
    return os << string(s.c_str(), s.length());
}
#endif // ICHAR_TRAITS_H ///:~
