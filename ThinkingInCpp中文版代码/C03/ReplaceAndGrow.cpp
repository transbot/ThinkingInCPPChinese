//: C03:ReplaceAndGrow.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <cassert>
#include <string>
using namespace std;

int main() {
    string mirrorListening("二更鼓儿敲，");
    string replacement("敲得泪珠儿对对往下掉。");

    // 第一个实参相当于说：“对超出现有字符串末尾的字符进行替换”：
    mirrorListening.replace(mirrorListening.size() ,
                    replacement.size(), replacement);    
    assert(mirrorListening == "二更鼓儿敲，"
                      "敲得泪珠儿对对往下掉。");
} ///:~