//: C04:Effector.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// Jerry Schwarz的“效果器”（effector）
#include <cassert>
#include <limits>  // 为了使用max()
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

// 截断并输出字符串的前缀部分（指定宽度）：
class Fixw {
    string str;
public:
    Fixw(const string& s, int width) : str(s, 0, width) {}
    friend ostream& operator<<(ostream& os, const Fixw& fw) {
        return os << fw.str;
    }
};

// 以二进制形式打印一个数字：
typedef unsigned long ulong;

class Bin {
    ulong n;
public:
    Bin(ulong nn) { n = nn; }
    friend ostream& operator<<(ostream& os, const Bin& b) {
        const ulong ULMAX = numeric_limits<ulong>::max();
        ulong bit = ~(ULMAX >> 1); // 设置最高位
        while (bit) {
            os << (b.n & bit ? '1' : '0');
            bit >>= 1;
        }
        return os;
    }
};

int main() {
    string words = "Things that make us happy, make us wise";
    // 以下循环每次都从字符串中截去一个字符，输出原始字符串不断缩短的“前缀”
    // 如果字符串包含的全是汉字和全角标点，请将--i修改成(i=i-2)
    for (int i = words.size(); --i >= 0;) {
        ostringstream s;
        s << Fixw(words, i);
        assert(s.str() == words.substr(0, i));
        cout << s.str() << endl;
    }

    ostringstream xs, ys;
    xs << Bin(0xCAFEBABEUL);
    assert(xs.str() == "1100""1010""1111""1110""1011""1010""1011""1110");
    cout << xs.str() << endl;

    ys << Bin(0x76543210UL);
    assert(ys.str() == "0111""0110""0101""0100""0011""0010""0001""0000");
    cout << ys.str() << endl;
} ///:~
