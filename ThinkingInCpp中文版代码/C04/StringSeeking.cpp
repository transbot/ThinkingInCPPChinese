//: C04:StringSeeking.cpp {-bor}{-dmc}
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 对字符串流进行读取和写入
#include <cassert>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string text = "We will hook no fish";
    stringstream ss(text);
    ss.seekp(0, ios::end);
    ss << " before its time.";
    assert(ss.str() == "We will hook no fish before its time.");
    // 将 "hook" 改为 "ship"
    ss.seekg(8, ios::beg);
    string word;
    ss >> word;
    assert(word == "hook");
    ss.seekp(8, ios::beg);
    ss << "ship";
    // 将"fish"改为"code"
    ss.seekg(16, ios::beg);
    ss >> word;
    assert(word == "fish");
    ss.seekp(16, ios::beg);
    ss << "code";
    assert(ss.str() == "We will ship no code before its time.");
    ss.str("A horse of a different color."); // 演示str()的重载版本
    assert(ss.str() == "A horse of a different color.");
} ///:~
