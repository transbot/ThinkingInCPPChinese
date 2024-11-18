//: C07:TokenIteratorTest.cpp {-g++}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <fstream>
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include "TokenIterator.h"
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
    char* fname = "TokenIteratorTest.cpp";
    if(argc > 1) fname = argv[1];
    ifstream in(fname);
    assure(in, fname);
    ostream_iterator<string> out(cout, "\n");
    typedef istreambuf_iterator<char> IsbIt;
    IsbIt begin(in), isbEnd;
    Delimiters delimiters(" \t\n~;()\"<>:{}[]+-=&*#.,/\\");
    TokenIterator<IsbIt, Delimiters>
    wordIter(begin, isbEnd, delimiters), end;
    vector<string> wordlist;
    copy(wordIter, end, back_inserter(wordlist));
    // 输出结果：
    copy(wordlist.begin(), wordlist.end(), out);
    *out++ = "-----------------------------------";

    // 使用字符数组作为源：
    char* cp = "typedef std::istreambuf_iterator<char> It";
    TokenIterator<char*, Delimiters>
    charIter(cp, cp + strlen(cp), delimiters), end2;
    vector<string> wordlist2;
    copy(charIter, end2, back_inserter(wordlist2));
    // 输出结果：
    copy(wordlist2.begin(), wordlist2.end(), out);
    *out++ = "-----------------------------------";

    // 使用deque<char>作为源：
    ifstream in2("TokenIteratorTest.cpp");
    deque<char> dc;
    copy(IsbIt(in2), IsbIt(), back_inserter(dc));
    TokenIterator<deque<char>::iterator, Delimiters>
    dcIter(dc.begin(), dc.end(), delimiters), end3;
    vector<string> wordlist3;
    copy(dcIter, end3, back_inserter(wordlist3));
    // 输出结果：
    copy(wordlist3.begin(), wordlist3.end(), out);
    *out++ = "-----------------------------------";
    
    // 重现之前的Wordlist.cpp示例：
    ifstream in3("TokenIteratorTest.cpp");
    TokenIterator<IsbIt, Delimiters>
    wordIter2(IsbIt(in3), isbEnd, delimiters);
    set<string> wordlist4;
    while(wordIter2 != end)
        wordlist4.insert(*wordIter2++);
    copy(wordlist4.begin(), wordlist4.end(), out);
} ///:~
