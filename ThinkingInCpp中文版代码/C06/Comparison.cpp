//: C06:Comparison.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// STL范围比较算法
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include "PrintSequence.h"
using namespace std;

int main() { 
    // string提供了一种简便的方式来创建字符范围，
    // 但通常应该优先使用原生的string操作。
    string s1("This is a test"); 
    string s2("This is a Test"); 
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl; 
    cout << "比较s1 & s1: " 
         << equal(s1.begin(), s1.end(), s1.begin()) << endl; 
    cout << "比较s1 & s2: " 
         << equal(s1.begin(), s1.end(), s2.begin()) << endl; 

    // 第一个字典序测试
    // 比较两个范围的字典序，返回true表示s1字典序小于s1（显然不会）
    cout << "字典序比较s1 & s1: " 
         << lexicographical_compare(s1.begin(), s1.end(), s1.begin(), s1.end()) << endl; 

    // 第二个字典序测试
    cout << "字典序比较s1 & s2: " 
         << lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) << endl; 

    // 第三个字典序测试
    cout << "字典序比较s2 & s1: " 
         << lexicographical_compare(s2.begin(), s2.end(), s1.begin(), s1.end()) << endl; 

    // 第四个字典序测试
    cout << "字典序比较逐渐缩短版的 "
         "s1 & 完全长度的s2: " << endl;          
    string s3(s1); // 将s3初始化为s1的拷贝
    while(s3.length() != 0) {  // 循环直到s3的长度为0
        bool result = lexicographical_compare( 
            s3.begin(), s3.end(), s2.begin(), s2.end()); 
        
        // 输出当前的s3和s2以及比较结果
        cout << s3 << endl << s2 << ", 结果 = " 
             << result << endl;         
        
        // 如果s3“字典序小于”s2，则跳出循环
        if(result == true) break; 

        // 否则删除s3的最后一个字符并继续
        s3 = s3.substr(0, s3.length() - 1); 
    } 
    
    // 找到两个范围开始不匹配的位置 
    pair<string::iterator, string::iterator> p = 
        mismatch(s1.begin(), s1.end(), s2.begin()); 
    // 然后从每个范围不匹配的迭代器开始，一直打印到范围的末尾
    print(p.first, s1.end(), "p.first", ""); 
    print(p.second, s2.end(), "p.second",""); 
} ///:~
