//: C06:ForEach.cpp {-mwcc}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用STL for_each()算法
//{L} Counted
#include <algorithm>
#include <iostream>
#include "Counted.h"
using namespace std;

// 函数对象
template<class T>
class DeleteT {
public:
    void operator()(T* x) { delete x; }
};

// 模板函数
template<class T>
void wipe(T* x) { delete x; }

int main() {
    CountedVector B("花");
    for_each(B.begin(), B.end(), DeleteT<Counted>());
    CountedVector C("妖");
    for_each(C.begin(), C.end(), wipe<Counted>);
} ///:~
