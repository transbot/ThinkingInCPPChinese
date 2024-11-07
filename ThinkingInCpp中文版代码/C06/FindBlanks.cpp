//: C06:FindBlanks.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示通过mem_fun_ref()来使用string::empty()
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include "../require.h"
using namespace std;

// 定义一个类型别名，用于表示字符串向量的迭代器
typedef vector<string>::iterator LSI;

int main(int argc, char* argv[]) {
    char* fname = "FindBlanks.cpp"; // 默认文件名为"FindBlanks.cpp"
    if(argc > 1) fname = argv[1];   // 但也可以通过命令行实参来指定其他文件

    ifstream in(fname);             // 打开文件
    assure(in, fname);              // 确保文件正确打开
    
    vector<string> vs;              // 该字符串向量用于存储文件中的每一行
    string s;                       // 该临时字符串用于读取每一行
    while(getline(in, s))           // 逐行读取文件
        vs.push_back(s);            // 将每一行添加到向量中
    vector<string> cpy = vs;        // 创建向量的一个拷贝，用于后续测试
    
    // 查找第一个空行
    LSI lsi = find_if(vs.begin(), vs.end(), 
                      mem_fun_ref(&string::empty));
    
    while(lsi != vs.end()) { // 如果找到了空行
        *lsi = "空行";       // 就将该行替换为"空行"
        // 继续查找下一个空行
        lsi = find_if(vs.begin(), vs.end(),
                      mem_fun_ref(&string::empty));
    }
    for(size_t i = 0; i < cpy.size(); i++)
        if(cpy[i].size() == 0)        // 如果原向量中的某一行是空行
            assert(vs[i] == "空行");  // 确认该行已被替换为"空行"
        else
            assert(vs[i] != "空行");  // 确认非空行未被替换
} ///:~

