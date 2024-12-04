//: C11:UnresponsiveUI.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} ZThread

// 由于缺乏多线程处理，因此造成了一个无响应的UI
#include <iostream>
#include <fstream>
#include <string>
#include "zthread/Thread.h"

using namespace std;
using namespace ZThread;

int main() {
    cout << "请按<Enter>键退出:" << endl;
    ifstream file("UnresponsiveUI.cpp");
    string line;
    while(getline(file, line)) {
        cout << line << endl;
        Thread::sleep(1000); // 时间单位为毫秒
    }
    // 从控制台读取输入
    cin.get();
    cout << "正在关闭..." << endl;
} ///:~
