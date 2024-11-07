//: C06:CountNotEqual_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <algorithm> 
#include <cstddef> 
#include <iostream> 
using namespace std;

// 统计不等于20的元素的数量(使用lambda表达式)
int main() {
    int a[] = { 10, 20, 30 };
    const size_t SIZE = sizeof a / sizeof a[0]; 

    // 使用lambda表达式
    int count = count_if(a, a + SIZE, [](int x) { return x != 20; }); 
    cout << count << endl; // 输出 2
}