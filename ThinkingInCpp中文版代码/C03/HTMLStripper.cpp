//: C03:HTMLStripper.cpp {RunByHand}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
//{L} ReplaceAll

// 该过滤器用于移除HTML标签和标记
#include <cassert>
#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include "ReplaceAll.h"
#include "../require.h"

using namespace std;

string& stripHTMLTags(string& s) {
    static bool inTag = false;
    bool done = false;
    while(!done) {
        if(inTag) {
            // 上一行开始了一个HTML标记但没有结束。必须继续查找'>'.
            size_t rightPos = s.find('>');
            if(rightPos != string::npos) {
                inTag = false;
                s.erase(0, rightPos + 1);
            } else {
                done = true;
                s.erase();
            }
        } else {
            // 查找标记的起始符号：
            size_t leftPos = s.find('<');
            if(leftPos != string::npos) {
                // 判断标记是否在同一行结束：
                size_t rightPos = s.find('>');
                if(rightPos == string::npos) {
                    inTag = done = true;
                    s.erase(leftPos);
                } else
                    s.erase(leftPos, rightPos - leftPos + 1);
            } else
                done = true;
        }
    }

    // 移除所有特殊HTML字符
    replaceAll(s, "&lt;", "<");
    replaceAll(s, "&gt;", ">");
    replaceAll(s, "&amp;", "&");
    replaceAll(s, "&nbsp;", " ");
    // 等等...
    return s;
}

int main(int argc, char* argv[]) {
    requireArgs(argc, 1,
               "用法: HTMLStripper 你的测试.html文件");
    ifstream in(argv[1]);
    assure(in, argv[1]);
    string s;
    while(getline(in, s))
        if(!stripHTMLTags(s).empty())
            cout << s << endl;
} ///:~
