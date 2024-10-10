//: C03:UhOh.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include <string>
#include <cassert>
using namespace std;

int main() {
    // 错误：不能用单个char来初始化
    //! string nothingDoing1('a');

    // 错误：不能用整数来初始化
    //! string nothingDoing2(0x37);

    // 但以下合法：
    string okay(5, 'a');
    assert(okay == string("aaaaa"));    
} ///:~
