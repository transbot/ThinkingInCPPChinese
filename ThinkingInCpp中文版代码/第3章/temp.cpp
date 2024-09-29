//: C03:Replace.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <cassert>
#include <cstddef> // 为了使用size_t
#include <string>
#include <iostream>
using namespace std;

void replaceChars(string& modifyMe,
    const string& findMe, const string& newChars) {

    // 从位置0开始，在modifyMe中查找要替换的字符串findMe
    size_t i = modifyMe.find(findMe, 0);
    
    // 是否找到了要替换的字符串？
    if(i != string::npos)
        // 使用newChars替换findMe
        modifyMe.replace(i, findMe.size(), newChars);
    cout << "未找到目标";
}

int main() {
    string mirrorListening = "一更鼓儿天，"
                             "这一去金川十呀么十七年。";
    string replacement("十八"); // 这是替换字符串
    string findMe("十一");      // 这是要被替换的字符串
    
    // 在mirrorListening中查找"十七"并用"十八"覆盖它
    replaceChars(mirrorListening, findMe, replacement);
    cout << mirrorListening;

    // 验证替换成功
    // assert(mirrorListening == "一更鼓儿天，"                              "这一去金川十呀么十八年。");                     
} ///:~
