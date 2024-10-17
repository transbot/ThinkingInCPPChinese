//: C04:ReadWriteBinaryFile.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include <iostream>
#include <fstream>

// 用于测试未格式化的I/O函数read()和get()。
// 本例首先向data.bin写入二进制数据，再从中读取。
// 注意，中译版新增示例，原书没有。
using namespace std;

int main() {
    // 写入部分
    ofstream outputFile("data.bin", ios::binary);  // 以二进制模式打开文件
    int data[] = {1, 2, 3, 4, 5};
    outputFile.write(reinterpret_cast<char*>(data), sizeof(data));
    outputFile.close();

    // 读取部分
    ifstream inputFile("data.bin", ios::binary);  // 以二进制模式打开文件
    int readData[sizeof(data)];
    inputFile.read(reinterpret_cast<char*>(readData), sizeof(data));
    inputFile.close();

    // 显示读取到的数据
    cout << "读取到的数据：";
    for (int i = 0; i < sizeof(data) / sizeof(int); ++i) {
        cout << readData[i] << " ";
    }
    cout << endl;

    return 0;
}