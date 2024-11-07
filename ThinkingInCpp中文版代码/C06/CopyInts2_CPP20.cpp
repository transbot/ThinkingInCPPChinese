//: C06:CopyInts2_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 忽略满足断言的整数
#include <algorithm> 
#include <cstddef> 
#include <iostream> 
using namespace std;

// // 一个自定义的断言（考虑修改成lambda表达式）
// bool gt15(int x) { 
//     return 15 < x; 
// }

int main() { 
    int a[] = { 10, 20, 30 }; 
    const size_t SIZE = sizeof a / sizeof a[0]; 
    int b[SIZE]; 

    // 使用lambda表达式作为谓词
    int* endb = remove_copy_if(a, a + SIZE, b, [](int x) { return x > 15; });     
    int* beginb = b; 
    while(beginb != endb)
        cout << *beginb++ << endl; // 只打印10 
} ///:~
