//: C06:FindBlanks_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示通过lambda表达式来使用string::empty()
// 同时演示“基于范围的for”
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
    char* fname = "FindBlanks_CPP20.cpp"; // 默认文件名为 "FindBlanks_CPP20.cpp"
    if (argc > 1) fname = argv[1];  // 但也可以通过命令行实参来指定其他文件

    ifstream in(fname);             // 打开文件
    assure(in, fname);              // 确保文件正确打开

    vector<string> vs;              // 该字符串向量用于存储文件中的每一行
    string s;                       // 该临时字符串用于读取每一行
    while (getline(in, s))          // 逐行读取文件
        vs.push_back(s);            // 将每一行添加到向量中
    vector<string> cpy = vs;        // 创建向量的一个拷贝，用于后续测试

    // 使用lambda表达式查找并替换空行
    auto is_empty = [](const string& str) { return str.empty(); };
    auto it = find_if(vs.begin(), vs.end(), is_empty);
    while (it != vs.end()) {
        *it = "空行";               // 将该行替换为"空行"
        it = find_if(it + 1, vs.end(), is_empty); // 继续查找下一个空行
    }

    // 验证结果
    for (size_t i = 0; i < cpy.size(); ++i) {
        if (cpy[i].empty())          // 如果原向量中的某一行是空行
            assert(vs[i] == "空行"); // 确认该行已被替换为"空行"
        else
            assert(vs[i] != "空行"); // 确认非空行未被替换
    }

    // 输出原向量（即指定文件）的内容，注意使用了现代C++常用的“基于范围的for”技术
    cout << "处理后的文件内容：" << endl;
    for (const auto& line : vs) {
        cout << line << endl;
    }

    return 0;
}