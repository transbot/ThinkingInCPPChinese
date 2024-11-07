//: C06:SetOperations.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 对已排序的范围执行集合运算
//{L} Generators
#include <algorithm>
#include <vector>
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

int main() {
    std::srand(std::time(nullptr));  // 设置随机数种子
    const int SZ = 30;
    char v[SZ + 1], v2[SZ + 1];
    CharGen g;

    // 生成、排序并打印两个字符数组
    generate(v, v + SZ, g);        
    generate(v2, v2 + SZ, g);
    sort(v, v + SZ);
    sort(v2, v + SZ);
    print(v, v + SZ, "v", "");
    print(v2, v2 + SZ, "v2", "");
    
    bool b = includes(v, v + SZ, v + SZ/2, v + SZ);
    cout.setf(ios::boolalpha);
    cout << "includes: " << b << endl;
    char v3[SZ*2 + 1], *end;
    end = set_union(v, v + SZ, v2, v2 + SZ, v3);
    print(v3, end, "set_union", "");
    end = set_intersection(v, v + SZ, v2, v2 + SZ, v3);
    print(v3, end, "set_intersection", "");
    end = set_difference(v, v + SZ, v2, v2 + SZ, v3);
    print(v3, end, "set_difference", "");
    end = set_symmetric_difference(v, v + SZ, v2, v2 + SZ, v3);
    print(v3, end, "set_symmetric_difference", "");
}
///:~
