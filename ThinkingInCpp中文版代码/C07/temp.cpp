#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <locale>
#include "../require.h"
using namespace std;

#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include "../require.h"
#include <boost/algorithm/string.hpp> // 使用 Boost 库进行分词

using namespace std;

// 假设文本文件采用 UTF-8 编码，并使用 Boost 库进行分词
void wordSet(const char* fileName) {
    ifstream source(fileName);
    assure(source, fileName);
    string line, word;
    set<string> chineseWords; // 存储不重复的汉字
    set<string> englishWords; // 存储不重复的英文单词

    while (getline(source, line)) {
        // 使用 Boost 分词，这里假设分词结果为单个汉字
        boost::split(chineseWords, line, boost::is_any_of(" "));

        // 提取英文单词的部分（可以根据实际情况调整正则表达式）
        boost::regex englishRegex("[a-zA-Z]+");
        boost::sregex_iterator iter(line.begin(), line.end(), englishRegex);
        boost::sregex_iterator end;
        while (iter != end) {
            englishWords.insert(iter->str());
            ++iter;
        }
    }

    // 输出结果
    cout << "不重复的汉字数量：" << chineseWords.size() << endl;
    cout << "不重复的英文单词数量：" << englishWords.size() << endl;
}

int main(int argc, char* argv[]) {
    if(argc > 1) // 如果在命令行提供了文件名实参，则使用该文件名
        wordSet(argv[1]);
    else         // 否则使用默认文件
        wordSet("WordSet.cpp");
} ///:~