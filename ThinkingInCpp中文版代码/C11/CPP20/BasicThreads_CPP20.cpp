//: C11:BasicThreads_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// Thread类最基本的应用
#include <iostream>
#include <thread>
#include "LiftOff_CPP20.h"

using namespace std;

int main() {
    try {
        // 创建一个LiftOff对象，倒计时10次，任务标识符默认为0
        LiftOff liftoff(10);
        // 创建一个线程，执行LiftOff对象的run方法
        std::thread t(&LiftOff::run, &liftoff);
        cout << "点火倒计时" << endl; // 打印等待消息
        // 等待线程结束
        t.join();
    } catch (const std::exception& e) {
        // 捕获并打印异常
        cerr << "异常: " << e.what() << endl;
    }
    return 0;
} ///:~