//: C03:Equivalence.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s2("That"), s1("This");
    // 左值是一个用引号包围的字面值
    // 而右值是一个string对象：
    if("That" == s2)
        cout << "匹配" << endl;
    // 左操作数是一个字符串，右操作数则是
    // 指向C风格null终止字符串的指针：
    if(s1 != s2.c_str())
        cout << "不匹配" << endl;
} ///:~
