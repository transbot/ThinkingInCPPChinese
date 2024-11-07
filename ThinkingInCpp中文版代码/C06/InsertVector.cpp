//: C06:InsertVector.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 将一个向量的内容追加到另一个向量上
#include <algorithm> 
#include <cassert> 
#include <cstddef> 
#include <iterator> 
#include <vector>
using namespace std;

int main() { 
    int a[] = { 10, 20, 30 }; 
    const size_t SIZE = sizeof a / sizeof a[0]; 
    vector<int> v1(a, a + SIZE); 
    vector<int> v2; // v2此处为空
    copy(v1.begin(), v1.end(), back_inserter(v2)); 
    assert(equal(v1.begin(), v1.end(), v2.begin()));
} ///:~
