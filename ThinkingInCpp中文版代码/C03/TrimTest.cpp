//: C03:TrimTest.cpp {O}
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include "TrimTest.h"

// 初始化静态数据
std::string TrimTest::s[TrimTest::NTESTS] = {
    " \t abcdefghijklmnop \t ",
    "abcdefghijklmnop \t ",
    " \t abcdefghijklmnop",
    "a", "ab", "abc", "a b c",
    " \t a b c \t ", " \t a \t b \t c \t ",
    "\t \n \r \v \f",
    "" // 空白字符串也必须测试
}; ///:~
