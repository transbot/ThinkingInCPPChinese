// C11:UnresponsiveUI_CPP20.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 由于缺乏多线程处理，因此造成了一个无响应的UI
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void readAndDisplayFile() {
    ifstream file("UnresponsiveUI_CPP20.cpp");
    string line;
    while(getline(file, line)) {
        cout << line << endl;
        this_thread::sleep_for(chrono::milliseconds(1000)); // 时间单位为毫秒
    }
}

int main() {
    cout << "请按<Enter>键退出:" << endl;

    // 创建一个线程来读取并显示文件内容
    thread fileThread(readAndDisplayFile);

    // 从控制台读取输入
    cin.get();

    // 等待文件读取线程结束
    fileThread.join();

    cout << "正在关闭..." << endl;
    return 0;
}