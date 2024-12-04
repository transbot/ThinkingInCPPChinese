// C11:SimplePriorities_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示线程优先级的使用（Windows）
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <windows.h>

using namespace std;

const double pi = 3.14159265358979323846;
const double e = 2.7182818284590452354;

class SimplePriorities {
    int countDown;
    volatile double d; // 不允许优化
    int id;

public:
    SimplePriorities(int ident = 0) : countDown(5), id(ident) {}
    ~SimplePriorities() {
        cout << id << " 完成" << endl;
    }
    friend ostream& operator<<(ostream& os, const SimplePriorities& sp) {
        return os << "#" << sp.id << " 优先级: " 
                  << GetThreadPriority(GetCurrentThread()) << " 计数: " << sp.countDown;
    }
    void run() {
        while(true) {
            // 执行耗时且可以中断的操作
            for(int i = 1; i < 100000; i++)
                d = d + (pi + e) / double(i);
            cout << *this << endl;
            if(--countDown == 0) return;
        }
    }
};

bool setThreadPriority(std::thread& t, int priority) {
    if (SetThreadPriority(t.native_handle(), priority) == 0) {
        cerr << "线程优先级设置失败: " << GetLastError() << endl;
        return false;
    }
    return true;
}

void highPriorityTask() {
    SimplePriorities sp;
    sp.run();
}

void lowPriorityTask(int id) {
    SimplePriorities sp(id);
    sp.run();
}

int main() {
    try {
        vector<thread> threads;

        // 创建高优先级线程
        thread high(highPriorityTask);
        if (!setThreadPriority(high, THREAD_PRIORITY_HIGHEST)) {
            cerr << "将线程优先级设置为“高”失败。" << endl;
        }
        threads.push_back(move(high));

        // 创建低优先级线程
        for(int i = 0; i < 5; i++) {
            thread low(lowPriorityTask, i);
            if (!setThreadPriority(low, THREAD_PRIORITY_LOWEST)) {
                cerr << "将线程优先级设置为“低”失败。" << endl;
            }
            threads.push_back(move(low));
        }

        // 等待所有线程完成
        for (auto& t : threads) {
            if (t.joinable()) {
                t.join();
            }
        }
    } catch(exception& e) {
        cerr << "main()中发生异常: " << e.what() << endl;
    }

    return 0;
}