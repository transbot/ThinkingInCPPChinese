//: C07:StringDeque.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 修改自StringVector.cpp 
#include <cstddef>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
    const char* fname = "StringDeque.cpp";
    if(argc > 1) fname = argv[1];
    ifstream in(fname);
    assure(in, fname);

    vector<string> vstrings;
    deque<string> dstrings;
    string line;

    // 测试读取到vector的时间
    clock_t ticks = clock();
    while(getline(in, line))
        vstrings.push_back(line);
    ticks = clock() - ticks;
    cout << "读取到vector: " << ticks << endl;

    // 对deque进行相同的测试：
    ifstream in2(fname);
    assure(in2, fname);
    ticks = clock();
    while(getline(in2, line))
        dstrings.push_back(line);
    ticks = clock() - ticks;
    cout << "读取到deque: " << ticks << endl;

    // 现在比较索引操作
    ticks = clock();
    for(size_t i = 0; i < vstrings.size(); i++) {
        ostringstream ss;
        ss << i;
        vstrings[i] = ss.str() + ": " + vstrings[i];
    }
    ticks = clock() - ticks;
    cout << "vector索引: " << ticks << endl;

    ticks = clock();
    for(size_t j = 0; j < dstrings.size(); j++) {
        ostringstream ss;
        ss << j;
        dstrings[j] = ss.str() + ": " + dstrings[j];
    }
    ticks = clock() - ticks;
    cout << "deque索引: " << ticks << endl;

    // 比较遍历操作
    ofstream tmp1("tmp1.tmp"), tmp2("tmp2.tmp");
    ticks = clock();
    copy(vstrings.begin(), vstrings.end(),
         ostream_iterator<string>(tmp1, "\n"));
    ticks = clock() - ticks;
    cout << "vector遍历: " << ticks << endl;

    ticks = clock();
    copy(dstrings.begin(), dstrings.end(),
         ostream_iterator<string>(tmp2, "\n"));
    ticks = clock() - ticks;
    cout << "deque遍历: " << ticks << endl;
} ///:~
