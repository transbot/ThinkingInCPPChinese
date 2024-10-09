//: C03:ReplaceAllTest.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <cassert>
#include <iostream>
#include <string>
#include "ReplaceAll.h"
using namespace std;

int main() {
  string text = "要在先祖的序列里寻找自己，"
                "要用生命为时光去乞讨身体。";
  replaceAll(text, "要", "不要");    
  assert(text == "不要在先祖的序列里寻找自己，不要用生命为时光去乞讨身体。");
} ///:~
