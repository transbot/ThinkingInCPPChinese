//: C03:SmallString2.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.


#include <string>
#include <iostream>

using namespace std;

int main() {
    string s1("What is the sound of one clam napping?");
    string s2("Anything worth doing is worth overdoing.");
    string s3("I saw Elvis in a UFO");

    // 拷贝前8个字符
    string s4(s1, 0, 8);
    cout << s4 << endl;  // 输出：What is 

    // 拷贝源字符串中间位置的6个字符
    string s5(s2, 15, 6);
    cout << s5 << endl;  // 输出：doing

    // 从中间位置拷贝到结尾
    string s6(s3, 6, 15);
    cout << s6 << endl;  // 输出：Elvis in a UFO

    // 合并多个字符串
    string quoteMe = s4 + "that" +
                     // substr()从元素20开始拷贝10个字符：
                     s1.substr(20, 10) + s5 +
                     // substr()从元素5开始拷贝最多100个字符，
                     // 或者一直拷贝到字符串末尾：
                     "with" + s3.substr(5, 100) +
                     // 像下面这样拷贝单个字符是允许的：
                     s1.substr(37, 1);
    cout << quoteMe << endl;  // 输出：What is that one clam doing with Elvis in a UFO?
} ///:~
