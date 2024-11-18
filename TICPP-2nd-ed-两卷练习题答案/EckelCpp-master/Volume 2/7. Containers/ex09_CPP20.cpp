// 打开一个通过命令行指定的英文文本文件。逐单词读取文件，使用multiset<string>创建每个单词的词频统计。
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
#include <cstdlib> // for exit

using namespace std;

int main(int argc, char* argv[]) {
    string filename = "ex09.txt"; // 默认文件名

    // 检查命令行参数
    if (argc > 1) {
        filename = argv[1];
    }

    ifstream source(filename, ios::in);
    if (!source) {
        cerr << "无法打开文件: " << filename << endl;
        return 1;
    }

    multiset<string> words;
    string buf;

    // 逐词读取文件内容并插入到multiset中
    while (source >> buf) {
        words.insert(buf);
    }

    // 统计每个单词的出现次数并输出
    auto it = words.begin();
    while (it != words.end()) {
        auto p = words.equal_range(*it);
        int count = distance(p.first, p.second);
        cout << *it << ": " << count << '\n';
        it = p.second;
    }

    return 0;
}