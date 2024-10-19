//: C05:Urand.h {-bor}
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 该随机数生成器生成不重复的随机数
#ifndef URAND_H
#define URAND_H

#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <ctime>

using std::size_t;
using std::bitset;

template<size_t UpperBound> class Urand {
    bitset<UpperBound> used;

public:
    Urand() { srand(time(0)); } // 初始化随机数    
    size_t operator()();        // “生成器”函数
};

template<size_t UpperBound> 
inline size_t Urand<UpperBound>::operator()() {
    if (used.count() == UpperBound)
        used.reset(); // 重新开始（清空bitset）
    
    size_t newval;

    while (used[newval = rand() % UpperBound])
        ; // 直到找到不重复的值
    
    used[newval] = true;
    return newval;
}

#endif // URAND_H ///:~
