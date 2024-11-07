//: C06:CopyStrings_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
using namespace std;

int main() {
    // 使用lambda表达式定义一个谓词函数
    // 对auto gt_n = [](int n) { return n > 4; };的解释：
    //   - auto：让编译器自动推断类型，这里会推断为一个可调用对象。
    //   - []：捕获列表，这里没有捕获任何外部变量。
    //   - (int n)：参数列表，表示函数接受一个int参数。
    //   - return n > 4;：函数体，返回一个布尔值，表示n是否大于4。
    auto  gt_n = [](int n) { return n > 4; };

    cout << gt_n(3) << endl; // 打印0
    cout << gt_n(5) << endl; // 打印1
}