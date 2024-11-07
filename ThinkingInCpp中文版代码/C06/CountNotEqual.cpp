//: C06:CountNotEqual.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 统计不等于20的元素的数量
#include <algorithm> 
#include <cstddef> 
#include <functional> 
#include <iostream> 
using namespace std;

int main() { 
    int a[] = { 10, 20, 30 }; 
    const size_t SIZE = sizeof a / sizeof a[0]; 
    cout << count_if(a, a + SIZE, 
                     not1(bind1st(equal_to<int>(), 20))); // 输出 2 
} ///:~
