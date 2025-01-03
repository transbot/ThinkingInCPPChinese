//: C07:StringVector.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 一个字符串容器
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
    const char* fname = "StringVector.cpp";
    if(argc > 1) fname = argv[1];
    ifstream in(fname);
    assure(in, fname);
    vector<string> strings;
    string line;
    while(getline(in, line))
        strings.push_back(line);

    // 对字符串进行操作...
    int i = 1;
    vector<string>::iterator w;
    for(w = strings.begin(); w != strings.end(); w++) {
        ostringstream ss;
        ss << i++;
        *w = ss.str() + ": " + *w;
    }

    // 现在输出它们
    copy(strings.begin(), strings.end(),
         ostream_iterator<string>(cout, "\n"));

    // 由于不是指针，因此字符串对象会被自动清理！
} ///:~
