//: C06:CopyInts.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 不使用显式循环来拷贝int值
#include <algorithm>
#include <cassert> 
#include <cstddef> // 为了使用size_t
using namespace std;

int main() {
    int a[] = { 10, 20, 30 };
    const size_t SIZE = sizeof a / sizeof a[0];
    int b[SIZE];
    copy(a, a + SIZE, b);
    for(size_t i = 0; i < SIZE; ++i)
        assert(a[i] == b[i]);
} ///:~
