/*
创建一个set<char>，打开一个文件（文件名通过命令行提供），并逐字符读取该文件，
将每个char放入set中。打印结果，并注意观察。是否有一些字母没有在该文件中用到？
注：这个程序对原答案进行了修改，能自动报告文件中未使用的字母。
*/

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "用法: " << argv[0] << " filename" << endl;
        return 1;
    }

    set<char> chars;
    ifstream infile(argv[1]);

    if (!infile.is_open()) {
        cerr << "打开文件失败: " << argv[1] << endl;
        return 1;
    }

    char ch;
    while (infile.get(ch)) {
        // 将所有字母转换为小写，统一处理
        chars.insert(tolower(ch));
    }

    infile.close();

    cout << "文件中用到的字符（英语字母不区分大小写）:" << endl;
    for (char c : chars) {
        cout << c << " ";
    }
    cout << endl;

    // 分析缺失字母（考虑大小写）
    cout << "没有用到字母表中的以下字母:(不区分大小写):" << endl;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (chars.count(c) == 0) {
            cout << c << " ";
        }
    }
    cout << endl;

    return 0;
}