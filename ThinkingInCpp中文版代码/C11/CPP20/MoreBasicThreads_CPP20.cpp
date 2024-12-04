// C11:MoreBasicThreads_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 添加更多线程
#include <iostream>
#include <thread>
#include <vector>
#include "LiftOff_CPP20.h"

using namespace std;

int main() {
    const int SZ = 5;
    try {
        vector<thread> threads; // 用于存储线程对象的向量
        vector<LiftOff*> liftOffs; // 用于存储LiftOff对象的向量

        for(int i = 0; i < SZ; i++) {
            // 创建一个LiftOff对象，倒计时10次，任务标识符为i
            LiftOff* liftoff = new LiftOff(10, i);
            // 创建一个线程，执行LiftOff对象的run方法
            threads.emplace_back(&LiftOff::run, liftoff);
            // 存储LiftOff对象指针
            liftOffs.push_back(liftoff);
        }
        cout << "点火倒计时" << endl; // 打印等待消息
        // 等待所有线程结束
        for(auto& t : threads) {
            t.join();
        }
        // 清理动态分配的LiftOff对象
        for(LiftOff* liftoff : liftOffs) {
            delete liftoff;
        }
    } catch (const std::exception& e) {
        // 捕获并打印异常
        cerr << "异常: " << e.what() << endl;
    }
    return 0;
}