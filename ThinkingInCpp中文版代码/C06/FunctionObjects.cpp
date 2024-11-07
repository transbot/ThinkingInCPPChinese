//: C06:FunctionObjects.cpp {-bor}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示标准C++库中的预定义函数对象模板
// 有三个已在现代C++中弃用：not1，not2和bind2nd（bind1st也不例外）
// 参见代码中的注释，了解如何在添加/std:c++20开关的前提下编译通过
// {L} Generators
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

template<typename Contain, typename UnaryFunc>
void testUnary(Contain& source, Contain& dest, UnaryFunc f) {
    // 使用transform()的4参数版本
    transform(source.begin(), source.end(), dest.begin(), f); 
}

template<typename Contain1, typename Contain2, typename BinaryFunc>
void testBinary(Contain1& src1, Contain1& src2,
    Contain2& dest, BinaryFunc f) {
    // 使用transform()的5参数版本      
    transform(src1.begin(), src1.end(), src2.begin(), dest.begin(), f);
}

// 执行（求值）表达式，然后将表达式本身“字符串化”到打印语句中：
#define T(EXPR) EXPR; print(r.begin(), r.end(), "执行 " #EXPR " 之后");

// 用于布尔测试：
#define B(EXPR) EXPR; print(br.begin(), br.end(), "执行 " #EXPR " 之后");

// 布尔随机生成器：
struct BRand {
    bool operator()() {
        return rand() % 2 == 0;
    }
};

int main() {  
    const int SZ = 10;
    const int MAX = 50;
    vector<int> x(SZ), y(SZ), r(SZ);

    // 整数随机数生成器：
    URandGen urg(MAX);
    srand(time(0)); // 随机化
    generate_n(x.begin(), SZ, urg);
    generate_n(y.begin(), SZ, urg);

    // 每个元素加1以防止除以零：
    transform(y.begin(), y.end(), y.begin(), bind2nd(plus<int>(), 1));    
    // 上面这行代码在现代C++中应改为使用lambda表达式，因为bind2nd已被弃用：
    // transform(y.begin(), y.end(), y.begin(), [](int x) { return x + 1; });

    // 保证至少有一对元素是相等的（以测试equal_to）：
    x[0] = y[0];

    print(x.begin(), x.end(), "x");
    print(y.begin(), y.end(), "y");

    // 对每一对x和y元素执行数学运算，并将结果放入r中：
    T(testBinary(x, y, r, plus<int>()))       // 加
    T(testBinary(x, y, r, minus<int>()))      // 减
    T(testBinary(x, y, r, multiplies<int>())) // 乘
    T(testBinary(x, y, r, divides<int>()))    // 除
    T(testBinary(x, y, r, modulus<int>()))    // 模除
    T(testUnary(x, r, negate<int>()))         // 取反

    vector<bool> br(SZ); // 用于容纳布尔结果
    B(testBinary(x, y, br, equal_to<int>())) 
    B(testBinary(x, y, br, not_equal_to<int>())) 
    B(testBinary(x, y, br, greater<int>())) 
    B(testBinary(x, y, br, less<int>())) 
    B(testBinary(x, y, br, greater_equal<int>())) 
    B(testBinary(x, y, br, less_equal<int>()))    
    
    B(testBinary(x, y, br, not2(greater_equal<int>())))
    B(testBinary(x, y, br, not2(less_equal<int>())))
    // 上面这两行代码在现代C++中应改为使用lambda表达式，因为not2已被弃用：
    // B(testBinary(x, y, br, [](int a, int b) { return a < b; }));
    // B(testBinary(x, y, br, [](int a, int b) { return a > b; }));
    // 或者直接将not2替换为not_fn：
    // B(testBinary(x, y, br, not_fn(greater_equal<int>())))
    // B(testBinary(x, y, br, not_fn(less_equal<int>())))

    vector<bool> b1(SZ), b2(SZ);
    generate_n(b1.begin(), SZ, BRand());
    generate_n(b2.begin(), SZ, BRand());

    print(b1.begin(), b1.end(), "b1");
    print(b2.begin(), b2.end(), "b2");

    B(testBinary(b1, b2, br, logical_and<int>()))
    B(testBinary(b1, b2, br, logical_or<int>()))
    B(testUnary(b1, br, logical_not<int>()))

    B(testUnary(b1, br, not1(logical_not<int>())))
    // 上面这行代码在现代C++中应改为使用lambda表达式，因为not1已被弃用：
    // B(testUnary(b1, br, [](bool x) { return x; }));
    // 或者直接将not1替换为not_fn：
    // B(testUnary(b1, br, not_fn(logical_not<int>())))
} ///:~
