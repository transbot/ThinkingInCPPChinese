//: C03:StringReplace.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 在字符串中实现简单的查找和替换功能
#include <cassert>
#include <string>
using namespace std;

int main() {
    string s("A piece of text");
    string tag("$tag$");    
    s.insert(8, tag + ' ');    
    assert(s == "A piece $tag$ of text");    
    int start = s.find(tag);    
    assert(start == 8);    
    assert(tag.size() == 5);    
    s.replace(start, tag.size(), "hello there");  // 替代字符和被删除的字符在数量上不同  
    assert(s == "A piece hello there of text");
} ///:~
