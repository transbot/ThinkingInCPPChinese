//: C07:BitSet.cpp {-bor}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 测试bitset类
#include <bitset>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

const int SZ = 32; // 将bitset的大小定义为包含32个二进制位
typedef bitset<SZ> BS; // 为bitset<SZ>定义别名BS

// 生成一个随机bitset
template<int bits> bitset<bits> randBitset() {
    // rand()函数生成16位的随机数，这个数将用于初始化bitset r的低16位
    bitset<bits> r(rand());

    // 通过循环不断调用rand()，每次生成16位随机数，
    // 然后将这些随机数拼接起来（通过按位OR），形成一个
    // 完整的、总共有bits位的随机bitset。
    for(int i = 0; i < bits/16 - 1; i++) {
        r <<= 16; // 左移16位
        // 使用新的16位与当前bitset进行按位OR操作，填充剩余的位
        r |= bitset<bits>(rand());
    }
    return r; // 返回生成的bitset
}

int main() {
    srand(time(0)); // 初始化随机数生成器

    // 输出不同大小的bitset的字节数
    cout << "sizeof(bitset<16>) = " << sizeof(bitset<16>) << endl;
    cout << "sizeof(bitset<32>) = " << sizeof(bitset<32>) << endl;
    cout << "sizeof(bitset<48>) = " << sizeof(bitset<48>) << endl;
    cout << "sizeof(bitset<64>) = " << sizeof(bitset<64>) << endl;
    cout << "sizeof(bitset<65>) = " << sizeof(bitset<65>) << endl;

    // 创建两个随机生成的bitset对象（32位）
    BS a(randBitset<SZ>()), b(randBitset<SZ>());

    // 将bitset转换为unsigned long类型
    unsigned long ul = a.to_ulong();
    cout << a << endl; // 输出bitset a

    // 将字符串转换为bitset
    string cbits("111011010110111");
    cout << "作为字符串 = " << cbits << endl;

    // 使用整个字符串来初始化bitset
    cout << BS(cbits) << " [BS(cbits)]" << endl;

    // 从字符串的索引2开始到末尾，用这个子串来初始化bitset
    cout << BS(cbits, 2) << " [BS(cbits, 2)]" << endl;

    // 从字符串索引2开始到索引11，用这个子串来初始化bitset
    cout << BS(cbits, 2, 11) << " [BS(cbits, 2, 11)]" << endl;

    // 输出bitset a和b
    cout << a << " [a]" << endl;
    cout << b << " [b]" << endl;

    // 按位AND操作
    cout << (a & b) << " [a & b]" << endl;
    cout << (BS(a) &= b) << " [a &= b]" << endl;

    // 按位OR操作
    cout << (a | b) << " [a | b]" << endl;
    cout << (BS(a) |= b) << " [a |= b]" << endl;

    // 按位XOR操作
    cout << (a ^ b) << " [a ^ b]" << endl;
    cout << (BS(a) ^= b) << " [a ^= b]" << endl;
    cout << a << " [a]" << endl; // 供参考

    // 逻辑左移操作（用0填充）
    cout << (BS(a) <<= SZ/2) << " [a <<= (SZ/2)]" << endl;
    cout << (a << SZ/2) << endl;
    cout << a << " [a]" << endl; // 供参考

    // 逻辑右移操作（用0填充）
    cout << (BS(a) >>= SZ/2) << " [a >>= (SZ/2)]" << endl;
    cout << (a >> SZ/2) << endl;
    cout << a << " [a]" << endl; // 供参考

    // 设置所有位为1
    cout << BS(a).set() << " [a.set()]" << endl;

    // 设置某个特定位为1
    for(int i = 0; i < SZ; i++)
        if(!a.test(i)) {
            cout << BS(a).set(i) << " [a.set(" << i <<")]" << endl;
            break; // 只做一个例子
        }

    // 重置所有位为0
    cout << BS(a).reset() << " [a.reset()]" << endl;

    // 重置某个特定位为0
    for(int j = 0; j < SZ; j++)
        if(a.test(j)) {
            cout << BS(a).reset(j) << " [a.reset(" << j <<")]" << endl;
            break; // 只做一个例子
        }

    // 翻转所有位
    cout << BS(a).flip() << " [a.flip()]" << endl;

    // 按位取反
    cout << ~a << " [~a]" << endl;
    cout << a << " [a]" << endl; // 供参考

    // 翻转某个特定位
    cout << BS(a).flip(1) << " [a.flip(1)]" << endl;

    // 创建一个空的bitset
    BS c;
    cout << c << " [c]" << endl;

    // 输出bitset c的统计信息
    cout << "c.count() = " << c.count() << endl;
    cout << "c.any() = " << (c.any() ? "true" : "false") << endl;
    cout << "c.none() = " << (c.none() ? "true" : "false") << endl;

    // 设置某些位（即设为1）
    c[1].flip(); c[2].flip();
    cout << c << " [c]" << endl;
    cout << "c.count() = " << c.count() << endl;
    cout << "c.any() = " << (c.any() ? "true" : "false") << endl;
    cout << "c.none() = " << (c.none() ? "true" : "false") << endl;

    // 数组索引操作
    c.reset();
    for(size_t k = 0; k < c.size(); k++)
        if(k % 2 == 0)
            c[k].flip();
    cout << c << " [c]" << endl;

    // 重置bitset c
    c.reset();

    // 随机设置某些位
    for(size_t ii = 0; ii < c.size(); ii++)
        c[ii] = (rand() % 100) < 25;
    cout << c << " [c]" << endl;

    // 检查某一位是否为1
    if(c[1])
        cout << "c[1] == true" << endl;
    else
        cout << "c[1] == false" << endl;
} ///:~