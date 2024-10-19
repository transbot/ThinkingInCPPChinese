//: C03:StrSize.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <string>
#include <iostream>
using namespace std;

int main() {
    string mirrorListening("所以期待渡鸦的只言片语。");
    cout << mirrorListening << endl;

    // 字符串当前实际包含多少数据？size是指当前大小
    cout << "大小 = " << mirrorListening.size() << endl;

    // 不重新分配内存的情况下总共可以存储多少？capacity是指最大容量
    cout << "容量 = " << mirrorListening.capacity() << endl;

    // 在mirrorListening[4]之前（第三个汉字之前）插入指定的字符串：
    mirrorListening.insert(4, "守候在除夕");
    cout << mirrorListening << endl;

    // 显示字符串的当前大小和容量
    cout << "大小 = " << mirrorListening.size() << endl;
    cout << "容量 = " << mirrorListening.capacity() << endl;

    // 确保有足够的空间
    mirrorListening.reserve(500);

    // 将指定的字符串追加到字符串末尾
    mirrorListening.append("天青地黑万籁俱寂没有踪迹，她早已经在镜中给了未来以定义。");
    cout << mirrorListening << endl;

    // 显示字符串的当前大小和容量
    cout << "大小 = " << mirrorListening.size() << endl;
    cout << "容量 = " << mirrorListening.capacity() << endl;
} ///:~
