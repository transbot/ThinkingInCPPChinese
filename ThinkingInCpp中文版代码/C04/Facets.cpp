//: C04:Facets.cpp {-bor}{-g++}{-mwcc}{-edg}
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 更改货币符号
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main() {
    // 更改为法语/法国区域设置
    locale loc("fr-FR");
    cout.imbue(loc);
    string currency = use_facet<moneypunct<char> >(loc).curr_symbol();
    char point = use_facet<moneypunct<char> >(loc).decimal_point();
    cout << "我今天赚了" << currency << 123.45 << "欧！" << endl;
} ///:~
