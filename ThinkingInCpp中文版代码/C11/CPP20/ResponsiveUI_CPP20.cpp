// C11:ResponsiveUI_CPP20.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 通过多线程处理来实现响应灵敏的UI
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class DisplayTask {
    ifstream in;
    string line;
    bool quitFlag;

public:
    DisplayTask(const string& file) : quitFlag(false) {
        in.open(file);
        if (!in.is_open()) {
            throw runtime_error("无法打开文件");
        }
    }
    ~DisplayTask() {
        in.close();
    }
    void run() {
        while(getline(in, line) && !quitFlag) {
            cout << line << endl;
            this_thread::sleep_for(chrono::milliseconds(1000)); // 模拟长时间运行的任务
        }
    }
    void quit() {
        quitFlag = true;
    }
};

int main() {
    try {
        cout << "请按<Enter>键退出:" << endl;
        DisplayTask dt("ResponsiveUI_CPP20.cpp");
        thread t(&DisplayTask::run, &dt);
        cin.get();
        dt.quit();
        t.join();
    } catch(const exception& e) {
        cerr << "异常: " << e.what() << endl;
    }
    cout << "正在关闭..." << endl;
    return 0;
}