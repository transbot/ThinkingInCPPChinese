//: C03:TrimTest.cpp {O}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include "TrimTest.h"

// Initialize static data
std::string TrimTest::s[TrimTest::NTESTS] = {
  " \t abcdefghijklmnop \t ",
  "abcdefghijklmnop \t ",
  " \t abcdefghijklmnop",
  "a", "ab", "abc", "a b c",
  " \t a b c \t ", " \t a \t b \t c \t ",
  "\t \n \r \v \f",
  "" // Must also test the empty string
}; ///:~
