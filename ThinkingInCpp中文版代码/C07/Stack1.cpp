//: C07:Stack1.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示STL stack
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// 请自行增删注释符号以使用不同版本
typedef stack<string> Stack1; // 默认：deque<string>
// typedef stack<string, vector<string>> Stack2;
// typedef stack<string, list<string>> Stack3;

int main() {
    ifstream in("Stack1.cpp");
    Stack1 textlines; // 尝试不同版本

    // 读取文件并将行存储到栈中
    string line;
    while(getline(in, line))
        textlines.push(line + "\n");

    // 打印栈中存储的行，打印后弹出
    while(!textlines.empty()) {
        cout << textlines.top();
        textlines.pop();
    }
} ///:~
