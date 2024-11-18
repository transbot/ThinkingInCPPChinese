//: C07:Valarray2.cpp {-bor}{-dmc}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示切片和掩码
#include "PrintValarray.h"
using namespace std;

int main() {
    int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    valarray<int> v(data, 12);

    // 使用切片提取一个子集
    valarray<int> r1(v[slice(0, 4, 3)]);
    print("slice(0,4,3)", r1);

    // 条件提取
    valarray<int> r2(v[v > 6]);
    print("大于6的元素", r2);

    /* 求第一列的平方
       注意，若将valarray视为二维数组的一维展开形式，
       那么slice方法可以用来提取逻辑上的“列”。
       例如，{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }可以展开成4x3的数组：
       1  2  3
       4  5  6
       7  8  9
       10 11 12
       slice(0, 3, 4)从valarray的位置0开始，以步长3提取总共4个元素的一个子集，
       这正好可以提取上述数组的“第一列”，即{ 1, 4, 7, 10}。 */
    v[slice(0, 4, 3)] *= valarray<int>(v[slice(0, 4, 3)]);
    print("第一列求平方后", v);

    // 恢复第一列
    int idx[] = { 1, 4, 7, 10 };
    valarray<int> save(idx, 4);
    v[slice(0, 4, 3)] = save;
    print("恢复后的v", v);

    // gslice()用于多维切片，可以提取出更高维的子集
    // 提取二维子集：{ { 1, 3, 5 }, { 7, 9, 11 } }
    // 详情请参见正文
    valarray<size_t> siz(2);
    siz[0] = 2;
    siz[1] = 3;
    valarray<size_t> gap(2);
    gap[0] = 6;
    gap[1] = 2;
    valarray<int> r3(v[gslice(0, siz, gap)]);
    print("二维切片", r3);

    // 使用布尔掩码提取子集（布尔掩码的所有元素必须是bool类型）
    valarray<bool> mask(false, 5);
    mask[1] = mask[2] = mask[4] = true;
    valarray<int> r4(v[mask]);
    print("v[mask]", r4);

    // 使用索引掩码提取子集（索引掩码的元素类型必须是size_t类型）
    // 索引掩码中的元素表示要提取的元素在原valarray中的索引
    size_t idx2[] = { 2, 2, 3, 6 };
    valarray<size_t> mask2(idx2, 4);
    valarray<int> r5(v[mask2]);
    print("v[mask2]", r5);

    // 使用索引掩码进行赋值
    valarray<char> text("now is the time", 15);
    valarray<char> caps("NITT", 4);
    valarray<size_t> idx3(4);
    idx3[0] = 0;
    idx3[1] = 4;
    idx3[2] = 7;
    idx3[3] = 11;
    text[idx3] = caps;
    print("首字母大写", text);

    return 0;
} ///:~
