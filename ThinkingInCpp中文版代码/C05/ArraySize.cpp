//: C05:ArraySize.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <cstddef>
using std::size_t;

template<size_t R, size_t C, typename T> 
void init1(T a[R][C]) { 
    for(size_t i = 0; i < R; ++i) 
        for(size_t j = 0; j < C; ++j) 
            a[i][j] = T(); 
}

template<size_t R, size_t C, class T> 
void init2(T (&a)[R][C]) { // 引用参数 
    for(size_t i = 0; i < R; ++i) 
        for(size_t j = 0; j < C; ++j) 
            a[i][j] = T(); 
}

int main() { 
    int a[10][20]; 
    init1<10,20>(a); // 必须指定大小 
    init2(a);        // 自动推断大小
} ///:~
