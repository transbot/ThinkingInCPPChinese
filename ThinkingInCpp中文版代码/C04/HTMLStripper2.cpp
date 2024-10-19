//: C04:HTMLStripper2.cpp {RunByHand}
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} ../C03/ReplaceAll
// 该过滤器用于移除HTML标签和标记
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "../C03/ReplaceAll.h"
#include "../require.h"
using namespace std;

string& stripHTMLTags(string& s) throw(runtime_error) {
    size_t leftPos;
    while ((leftPos = s.find('<')) != string::npos) {
        size_t rightPos = s.find('>', leftPos + 1);
        if (rightPos == string::npos) {
            ostringstream msg;
            msg << "不完整的HTML标签开始于位置："
                << leftPos;
            throw runtime_error(msg.str());
        }
        s.erase(leftPos, rightPos - leftPos + 1);
    }
    // 移除所有特殊HTML字符
  replaceAll(s, "&lt;", "<");
  replaceAll(s, "&gt;", ">");
  replaceAll(s, "&amp;", "&");
  replaceAll(s, "&nbsp;", " ");
  // Etc...
  return s;
}

int main(int argc, char* argv[]) {
    requireArgs(argc, 1, "用法: HTMLStripper2 你的测试.html文件");
    ifstream in(argv[1]);
    assure(in, argv[1]);
    // 将整个文件读入字符串；然后移除特殊字符
    ostringstream ss;
    ss << in.rdbuf();
    try {
        string s = ss.str();
        cout << stripHTMLTags(s) << endl;
        return EXIT_SUCCESS;
    } catch (runtime_error& x) {
        cout << x.what() << endl;
        return EXIT_FAILURE;
    }
} ///:~
