//: C04:Locale.cpp {-bor} {-g++} {-edg} {RunByHand}
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示本地化（locale）设置的效果
#include <iostream>
#include <locale>
using namespace std;

int main() {
    locale def;

    // 看看当前locale什么
    cout << def.name() << endl;
    locale current = cout.getloc();
    cout << current.name() << endl;
    float val = 12.34;
    cout << val << endl;

    // 将locale更改为法语/法国
    cout.imbue(locale("fr-FR")); 
    current = cout.getloc();
    cout << current.name() << endl;
    cout << val << endl;

    cout << "请输入字面值123,45: " ;
    cin.imbue(cout.getloc());
    cin >> val;
    cout << val << endl;
    cout.imbue(def);
    cout << val << endl;
} ///:~
