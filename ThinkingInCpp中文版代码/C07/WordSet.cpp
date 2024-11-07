//: C07:WordSet.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include "../require.h"
using namespace std;

// 该函数读取指定的文件并将其中的英文单词存储到集合中
void wordSet(const char* fileName) {
    ifstream source(fileName); // 打开文件
    assure(source, fileName);  // 确保文件成功打开
    string word;
    set<string> words;         // 创建一个集合来存储不重复的单词

    // 从文件中逐个读取单词，并将其插入到集合中
    while(source >> word)
        words.insert(word);

    // 使用输出流迭代器将集合中的单词打印到控制台，每个单词一行
    copy(words.begin(), words.end(),
         ostream_iterator<string>(cout, "\n"));
    cout << "不重复的单词的数量:"
         << words.size() << endl;
}

int main(int argc, char* argv[]) {
    if(argc > 1) // 如果在命令行提供了文件名实参，则使用该文件名
        wordSet(argv[1]);
    else         // 否则使用默认文件
        wordSet("WordSet.cpp");
} ///:~