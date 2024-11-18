//: C07:BitSet_CPP20.cpp
// 使用现代C++技术改进的bitset测试程序

#include <bitset>
#include <random>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

constexpr int SZ = 32; // 将bitset的大小定义为包含32个二进制位
using BS = bitset<SZ>; // 为bitset<SZ>定义别名BS

// 生成一个随机bitset
template<int bits> bitset<bits> randBitset() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dist(0, (1 << 16) - 1); // 生成0到2^16-1之间的随机数

    bitset<bits> r(dist(gen)); // 初始化bitset的第一个16位

    for(int i = 0; i < bits / 16 - 1; i++) {
        r <<= 16; // 左移16位
        r |= bitset<bits>(dist(gen)); // 使用新的16位与当前bitset进行按位OR操作，填充剩余的位
    }
    return r; // 返回生成的bitset
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // 初始化随机数生成器

    // 输出不同大小的bitset的字节数
    cout << "sizeof(bitset<16>) = " << sizeof(bitset<16>) << " 字节" << endl;
    cout << "sizeof(bitset<32>) = " << sizeof(bitset<32>) << " 字节" << endl;
    cout << "sizeof(bitset<48>) = " << sizeof(bitset<48>) << " 字节" << endl;
    cout << "sizeof(bitset<64>) = " << sizeof(bitset<64>) << " 字节" << endl;
    cout << "sizeof(bitset<65>) = " << sizeof(bitset<65>) << " 字节" << endl;

    // 创建两个随机生成的bitset对象
    BS a(randBitset<SZ>()), b(randBitset<SZ>());

    // 将bitset转换为unsigned long类型
    auto ul = a.to_ulong();
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
    cout << (BS(a) <<= SZ / 2) << " [a <<= (SZ/2)]" << endl;
    cout << (a << SZ / 2) << endl;
    cout << a << " [a]" << endl; // 供参考

    // 逻辑右移操作（用0填充）
    cout << (BS(a) >>= SZ / 2) << " [a >>= (SZ/2)]" << endl;
    cout << (a >> SZ / 2) << endl;
    cout << a << " [a]" << endl; // 供参考

    // 设置所有位为1
    cout << BS(a).set() << " [a.set()]" << endl;

    // 设置某个特定位为1
    for(int i = 0; i < SZ; i++) {
        if(!a.test(i)) {
            cout << BS(a).set(i) << " [a.set(" << i <<")]" << endl;
            break; // 只做一个例子
        }
    }

    // 重置所有位为0
    cout << BS(a).reset() << " [a.reset()]" << endl;

    // 重置某个特定位为0
    for(int j = 0; j < SZ; j++) {
        if(a.test(j)) {
            cout << BS(a).reset(j) << " [a.reset(" << j <<")]" << endl;
            break; // 只做一个例子
        }
    }

    // 翻转所有位
    cout << BS(a).flip() << " [a.flip()]" << endl;

    // 按位取反
    cout << ~a << " [~a]" << endl;
    cout << a << " [a]" << endl; // 供参考

    // 反转某个特定位
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
    for(size_t k = 0; k < c.size(); k++) {
        if(k % 2 == 0) {
            c[k].flip();
        }
    }
    cout << c << " [c]" << endl;

    // 重置bitset c
    c.reset();

    // 随机设置某些位
    for(size_t ii = 0; ii < c.size(); ii++) {
        c[ii] = (rand() % 100) < 25;
    }
    cout << c << " [c]" << endl;

    // 检查某一位是否为1
    if(c[1]) {
        cout << "c[1] == true" << endl;
    } else {
        cout << "c[1] == false" << endl;
    }
}