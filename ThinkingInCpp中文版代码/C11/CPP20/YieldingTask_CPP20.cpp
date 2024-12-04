// C11:YieldingTask_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用yield()建议何时切换线程
#include <iostream>
#include <thread>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

class YieldingTask {
    int countDown;
    int id;

public:
    YieldingTask(int ident = 0) : countDown(5), id(ident) {}
    ~YieldingTask() {
        cout << id << " 完成" << endl;
    }
    friend ostream& operator<<(ostream& os, const YieldingTask& yt) {
        return os << "#" << yt.id << ": " << yt.countDown;
    }
    void run() {
        while(true) {
            cout << *this << endl;
            if(--countDown == 0) return;
            this_thread::yield(); // 建议线程调度器切换到其他线程
        }
    }
};

int main() {
    try {
        vector<unique_ptr<thread>> threads;
        for(int i = 0; i < 5; i++) {
            auto task = make_unique<YieldingTask>(i);
            threads.emplace_back(make_unique<thread>([task = move(task)]() {
                task->run();
            }));
        }

        // 等待所有线程完成
        for (auto& t : threads) {
            t->join();
        }
    } catch(exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}