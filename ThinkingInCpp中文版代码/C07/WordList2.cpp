//: C07:WordList2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示istreambuf_iterator和插入迭代器
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
    char* fname = "WordList2.cpp";
    if(argc > 1) fname = argv[1];
    ifstream in(fname);
    assure(in, fname);
    istreambuf_iterator<char> p(in), end;
    set<string> wordlist;
    while(p != end) {
        string word;
        insert_iterator<string> ii(word, word.begin());
        // 寻找第一个字母字符：
        while(p != end && !isalpha(*p))
            ++p;
        // 一直拷贝，直到遇到第一个非字母字符：
        while(p != end && isalpha(*p))
            *ii++ = *p++;
        if(word.size() != 0)
            wordlist.insert(word);
    }
    // 输出结果：
    copy(wordlist.begin(), wordlist.end(), 
        ostream_iterator<string>(cout, "\n"));
} ///:~
