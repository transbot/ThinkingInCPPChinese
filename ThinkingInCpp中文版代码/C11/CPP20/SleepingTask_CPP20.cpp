// C11:SleepingTask_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 调用sleep_for()以暂停一段时间
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

class SleepingTask {
    int countDown;
    int id;

public:
    SleepingTask(int ident = 0) : countDown(5), id(ident) {}
    ~SleepingTask() {
        cout << id << " 完成" << endl;
    }
    friend ostream& operator<<(ostream& os, const SleepingTask& st) {
        return os << "#" << st.id << ": " << st.countDown;
    }
    void run() {
        while(true) {
            try {
                cout << *this << endl;
                if(--countDown == 0) return;
                this_thread::sleep_for(chrono::milliseconds(100)); // 暂停100毫秒
            } catch(exception& e) {
                cerr << id << "线程发生异常: " << e.what() << endl;
            }
        }
    }
};

int main() {
    try {
        vector<unique_ptr<thread>> threads;
        for(int i = 0; i < 5; i++) {
            auto task = make_unique<SleepingTask>(i);
            threads.emplace_back(make_unique<thread>([task = move(task)]() {
                task->run();
            }));
        }

        // 等待所有线程完成
        for (auto& t : threads) {
            t->join();
        }
    } catch(exception& e) {
        cerr << "main()中发生异常: " << e.what() << endl;
    }

    return 0;
}