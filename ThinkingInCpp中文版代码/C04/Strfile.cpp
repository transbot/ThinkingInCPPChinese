//: C04:Strfile.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示文件流I/O，
// 并演示get()和getline()之间的区别。
#include <fstream>
#include <iostream>
#include "../require.h"
using namespace std;

int main() {
    const int SZ = 100; // 指定缓冲区大小
    char buf[SZ];
    {
        ifstream in("Strfile.cpp");  // 读取
        assure(in, "Strfile.cpp");   // 验证是否打开
        ofstream out("Strfile.out"); // 写入
        assure(out, "Strfile.out");  // 验证是否打开
        int i = 1;                   // 行号计数器

        // 较为不便的逐行输入：
        while (in.get(buf, SZ)) { // 在输入中保留\n
            in.get(); // 丢弃下一个字符(\n)
            cout << buf << endl; // 必须添加\n
            // 向文件输出和标准I/O无异：
            out << i++ << ": " << buf << endl;
        }
    } // 析构函数关闭in和out

    ifstream in("Strfile.out");
    assure(in, "Strfile.out");
    // 较为方便的逐行输入：
    while (in.getline(buf, SZ)) { // 移除\n
        char* cp = buf;
        while (*cp != ':')
            ++cp;
        cp += 2; // 跳过": "
        cout << cp << endl; // 还是必须要添加\n
    }
} ///:~

