//: C06:NumStringGen.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 一个随机数生成器，用于生成代表浮点数的字符串
#ifndef NUMSTRINGGEN_H
#define NUMSTRINGGEN_H
#include <cstdlib>
#include <string>

class NumStringGen {
    const int sz; // 要生成的数字的位数（其中包括一个小数点）
public:
    NumStringGen(int ssz = 5) : sz(ssz) {} // 构造函数，默认字符串长度为5
    std::string operator()() {
        std::string digits("0123456789");  // 只能从这些数位中选择
        const int ndigits = digits.size(); // 能使用的数位个数，这里是常量值10
        std::string r(sz, ' '); // 创建长度为sz的字符串，每个字符都初始化为空格

        // 填充字符串，避免首位为0
        // 限定首位是1-9，具体做法是生成一个0-8之间的随机数，
        // 再加上1，从而确保范围在1-9之间。
        r[0] = digits[std::rand() % (ndigits - 1)] + 1; 

        // 再填充其余位
        for(int i = 1; i < sz; ++i) 
            // 如果位数大于等于3且当前索引是中间位置，则插入小数点
            if(sz >= 3 && i == sz/2) r[i] = '.';
            // 否则插入其余数位
            else r[i] = digits[std::rand() % ndigits];
        return r;
    }
};
#endif // NUMSTRINGGEN_H ///:~
