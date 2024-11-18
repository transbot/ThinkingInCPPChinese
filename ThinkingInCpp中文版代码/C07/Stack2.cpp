//: C07:Stack2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 将list转换为stack
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <string>
#include <cstddef>
using namespace std;

// 预期的是一个stack 
template<class Stk>
void stackOut(Stk& s, ostream& os = cout) {
    while(!s.empty()) {
        os << s.top() << "\n";
        s.pop();
    }
}

class Line {
    string line;    // 不带前导空格的行
    size_t lspaces; // 前导空格的数量
public:
    Line(string s) : line(s) {
        lspaces = line.find_first_not_of(' ');
        if(lspaces == string::npos)
            lspaces = 0;
        line = line.substr(lspaces);
    }
    friend ostream& operator<<(ostream& os, const Line& l) {
        for(size_t i = 0; i < l.lspaces; i++)
            os << ' ';
        return os << l.line;
    }
    // 其他函数...
};

int main() {
    ifstream in("Stack2.cpp");
    list<Line> lines;
    // 读取文件并将行存储到列表中
    string s;
    while(getline(in, s))
        lines.push_front(s);
    // 将list转换为stack以进行打印
    stack<Line, list<Line>> stk(lines);
    stackOut(stk);
} ///:~
