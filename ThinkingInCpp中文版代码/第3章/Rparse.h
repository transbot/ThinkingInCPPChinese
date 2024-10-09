//: C03:Rparse.h
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

//: C03:Rparse.h
#ifndef RPARSE_H
#define RPARSE_H
#include <cstddef>
#include <string>
#include <vector>
#include "../TestSuite/Test.h"

using std::size_t;
using std::string;
using std::vector;

class RparseTest : public TestSuite::Test {
    // 这个私有成员用于存储多个单词
    vector<string> strings;

public:
    void parseForData() {
        // ';' 字符将是定界符
        string s("now.;sense;make;to;going;is;This");
        // 字符串的最后一个元素：
        int last = s.size();
        // 当前单词的开始位置：
        size_t current = s.rfind(';');
        // 从字符串的末尾反向遍历：
        while(current != string::npos) {
            // 将每个单词压入向量，
            // 在拷贝之前递增current以避免拷贝定界符：
            ++current;
            strings.push_back(s.substr(current, last - current));
            // 回到刚刚找到的定界符前面，并将last设为下一个单词的末尾：
            current -= 2;
            last = current + 1;
            // 寻找下一个定界符：
            current = s.rfind(';', current);
        }
        // 压入第一个单词——它前面没有定界符：
        strings.push_back(s.substr(0, last));
    }
    
    void testData() {
        // 以新顺序测试它们：
        test_(strings[0] == "This");
        test_(strings[1] == "is");
        test_(strings[2] == "going");
        test_(strings[3] == "to");
        test_(strings[4] == "make");
        test_(strings[5] == "sense");
        test_(strings[6] == "now.");
        string sentence;
        for(size_t i = 0; i < strings.size() - 1; i++)
            sentence += strings[i] += " ";
        // 手动添加最后一个单词以避免多余的空格：
        sentence += strings[strings.size() - 1];
        test_(sentence == "This is going to make sense now.");
    }
    
    void run() {
        parseForData();
        testData();
    }
};

#endif // RPARSE_H ///:~
