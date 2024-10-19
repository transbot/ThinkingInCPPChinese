//: C04:Ostring.cpp {RunByHand}
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示输出字符串流ostringstream
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    cout << "输入一个整数、一个浮点数和一个字符串： ";
    int i;
    float f;
    cin >> i >> f;
    cin >> ws; // 清除空白字符
    string stuff;
    getline(cin, stuff); // 获取行内其余内容
    ostringstream os;
    os << "整数 = " << i << endl;
    os << "浮点数 = " << f << endl;
    os << "字符串 = " << stuff << endl;
    string result = os.str();
    cout << result << endl;
} ///:~
