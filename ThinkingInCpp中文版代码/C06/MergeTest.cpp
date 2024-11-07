//: C06:MergeTest.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 测试对已排序范围执行“合并”
//{L} Generators
#include <algorithm>
#include "PrintSequence.h"
#include "Generators.h"
using namespace std;

int main() {
    const int SZ = 15;
    int a[SZ*2] = {0};

    // 生成的两个已排序范围都放到同一个数组中
    generate(a, a + SZ, SkipGen(0, 2));
    a[3] = 4; a[4] = 4;
    generate(a + SZ, a + SZ*2, SkipGen(1, 3));

    // 打印a的两部分
    print(a, a + SZ, "范围1", " ");
    print(a + SZ, a + SZ*2, "范围2", " ");

    int b[SZ*2] = {0}; // 将所有元素都初始化为零
    
    merge(a, a + SZ, a + SZ, a + SZ*2, b); // 将a的两部分合并到b中
    print(b, b + SZ*2, "执行merge", " ");  // 打印合并后的结果 
    
    // 重置b
    for(int i = 0; i < SZ*2; i++)
        b[i] = 0;

    // 原地合并
    inplace_merge(a, a + SZ, a + SZ*2);
    print(a, a + SZ*2, "执行inplace_merge", " ");
    int* end = set_union(a, a + SZ, a + SZ, a + SZ*2, b);
    print(b, end, "set_union", " ");
} ///:~
