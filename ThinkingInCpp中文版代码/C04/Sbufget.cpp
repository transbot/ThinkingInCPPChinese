//: C04:Sbufget.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 将文件复制到标准输出
#include <fstream>
#include <iostream>
#include "../require.h"
using namespace std;

int main() {
    ifstream in("Sbufget.cpp");
    assure(in);
    streambuf& sb = *cout.rdbuf(); // 指针解引用
    while (!in.get(sb).eof()) {
        if (in.fail())          // 发现空行
            in.clear();         // 清除所有错误标志位，使流恢复正常状态
        cout << char(in.get()); // 处理'\n'
    }
} ///:~