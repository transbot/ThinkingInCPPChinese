//: C03:Tracetst.cpp {-bor}
// 来自《C++编程思想, 第2版》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页https://bookzhou.com下载。

#include <iostream>
#include <fstream>
#include "../require.h"
using namespace std;

std::ofstream TRACEFILE__("TRACE1.OUT");
#define cout TRACEFILE__
int main() {
  ifstream f("temp.cpp");
  assure(f, "temp.cpp");
  cout << f.rdbuf(); // 将文件的内容转储到TRACE1.OUT文件中
} ///:~
