//: C03:AddStrings.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

int main() {  
    string s1("谁不是");
    string s2("错过了");
    string s3("四下报更的鼓声.");
    string s4("总有人偷偷拨弄镜月的指针");

    // 找到句点符号的索引位置，rfind()的详情参见下一节
    size_t peroidPos = s3.rfind('.');    

    // 使用operator+拼接字符串
    s1 = s1 + s2;
    assert(s1 == "谁不是错过了");    

    // 另一种拼接字符串的方法
    s1 += s3;
    assert(s1 == "谁不是错过了四下报更的鼓声.");   

    // 在确保索引有效的前提下，对右侧的字符串进行索引
    if (peroidPos < s3.size()) {    
        s1 += s4 + s3[peroidPos]; // 在最后添加一个句点
        assert(s1 == "谁不是错过了四下报更的鼓声.总有人偷偷拨弄镜月的指针.");        
    } else {
        cout << "索引无效" << endl;
    }
} ///:~
