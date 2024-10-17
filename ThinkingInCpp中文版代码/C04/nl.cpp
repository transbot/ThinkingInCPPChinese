//: C04:nl.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 自定义一个操纵元
#include <iostream>

using namespace std;

// nl代表new line
ostream& nl(ostream& os) {
    return os << '\n';
}

int main() {
    cout << "在" << nl << "每" << nl << "个" << nl
         << "字" << nl << "之" << nl << "间" << nl
         << "插" << nl << "入" << nl << "换" << nl
         << "行" << nl << "符" << nl;
} ///:~
