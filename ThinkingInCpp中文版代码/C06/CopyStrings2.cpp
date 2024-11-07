//: C06:CopyStrings2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 替换满足谓词的字符串
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
    string b[SIZE];

    // 使用replace_copy_if替换包含"七"的字符串
    string* endb = replace_copy_if(a, a + SIZE, b, contains_qi, "十八年");

    // 输出结果
    string* beginb = b;
    while(beginb != endb)
        cout << *beginb++ << endl;
} ///:~