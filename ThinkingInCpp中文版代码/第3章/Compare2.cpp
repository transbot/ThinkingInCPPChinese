//: C03:Compare2.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示重载的compare()
#include <cassert>
#include <string>
using namespace std;

int main() {
    string first("This is a day that will live in infamy");
    string second("I don't believe that this is what "
                  "I signed up for");
    // 比较两个字符串中的"his is"：
    assert(first.compare(1, 7, second, 22, 7) == 0);
    // 比较"his is a"和"his is w"：
    assert(first.compare(1, 9, second, 22, 9) < 0);
} ///:~
