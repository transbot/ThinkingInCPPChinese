//: C11:BasicThreads_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include <iostream>
#include <thread> // 使用现代C++多线程库
using namespace std;

class LiftOff {
    int count;
public:
    LiftOff(int countdown) : count(countdown) {}
    void operator()() {
        while (count > 0) {
            cout << count-- << "秒后点火" << endl;
            this_thread::sleep_for(chrono::seconds(1)); // 模拟倒计时
        }
        cout << "点火!" << endl;
    }
};

int main() {
    try {
        // 创建线程并启动LiftOff任务
        thread t(LiftOff(10)); 
        cout << "点火倒计时" << endl;

        // 等待线程结束
        t.join();
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return 0; ///:~
}
