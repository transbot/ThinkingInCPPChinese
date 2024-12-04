// C11:ThreadedExecutor_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用现代C++标准库实现类似ZThread::ThreadedExecutor的功能
#include <iostream>
#include <thread>
#include <vector>
#include "LiftOff_CPP20.h"

using namespace std;

class SimpleExecutor {
private:
    vector<thread> threads;

public:
    void execute(Runnable* task) {
        threads.emplace_back([task] {
            task->run();
            delete task; // 释放任务对象
        });
    }

    ~SimpleExecutor() {
        for (auto& t : threads) {
            if (t.joinable()) {
                t.join();
            }
        }
    }
};

int main() {
    try {
        SimpleExecutor executor;
        for(int i = 0; i < 5; i++) {
            executor.execute(new LiftOff(10, i));
        }
    } catch(const exception& e) {
        cerr << "异常: " << e.what() << endl;
    }
    cout << "所有任务已完成" << endl;
    return 0;
}