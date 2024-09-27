//: C03:StringStorage.h
// 来自《C++编程思想, 第2版》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#ifndef STRINGSTORAGE_H
#define STRINGSTORAGE_H
#include <iostream>
#include <string>
#include "../TestSuite/Test.h"
using std::cout;
using std::endl;
using std::string;

class StringStorageTest : public TestSuite::Test {
public:
  void run() {
    string s1("12345");
    // 要么将第一个拷贝给第二个，
    // 要么使用引用计数来模拟一次拷贝动作：
    string s2 = s1;
    test_(s1 == s2);
    // 无论如何，该语句都只能修改s1：
    s1[0] = '6';
    cout << "s1 = " << s1 << endl;  // 62345
    cout << "s2 = " << s2 << endl;  // 12345
    test_(s1 != s2);
  }
};
#endif // STRINGSTORAGE_H ///:~
