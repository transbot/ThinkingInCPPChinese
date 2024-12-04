//: C11:ResponsiveUI.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 通过多线程处理来实现响应灵敏的UI
#include <iostream>
#include <fstream>
#include <string>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

class DisplayTask : public Runnable {
    ifstream in;
    string line;
    bool quitFlag;

public:
    DisplayTask(const string& file) : quitFlag(false) {
        in.open(file.c_str());
    }
    ~DisplayTask() {
        in.close();
    }
    void run() {
        while(getline(in, line) && !quitFlag) {
            cout << line << endl;
            Thread::sleep(1000);
        }
    }
    void quit() {
        quitFlag = true;
    }
};

int main() {
    try {
        cout << "请按<Enter>键退出:" << endl;
        DisplayTask* dt = new DisplayTask("ResponsiveUI.cpp");
        Thread t(dt);
        cin.get();
        dt->quit();
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
    cout << "正在关闭..." << endl;
} ///:~
