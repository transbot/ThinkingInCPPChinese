//: C06:ReplaceStrings.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 原地替换字符串
#include <algorithm> 
#include <cstddef> 
#include <iostream> 
#include <string> 
using namespace std;

// 谓词：判断字符串中是否包含“七”字
// （同样考虑修改为lambda表达式）
bool contains_qi(const string& s) { 
    return s.find("七") != string::npos; 
}

int main() { 
    string a[] = {"这一去", "金川", "十呀么", "十七年"};
    const size_t SIZE = sizeof a / sizeof a[0]; 
    replace_if(a, a + SIZE, contains_qi, string("十八年")); 
    string* p = a; 
    while(p != a + SIZE)
        cout << *p++ << endl; 
} ///:~
