//: C11:OrnamentalGarden.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} ZThread
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Display.h"
#include "zthread/Thread.h"
#include "zthread/FastMutex.h"
#include "zthread/Guard.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/CountedPtr.h"
using namespace ZThread;
using namespace std;

class Count : public Cancelable {
    FastMutex lock;
    int count;
    bool paused, canceled;

public:
    Count() : count(0), paused(false), canceled(false) {}
    int increment() {
        // 注释掉下一行以查看计数失败的情况：
        Guard<FastMutex> g(lock);
        int temp = count;
        if (rand() % 2 == 0) // 半数时间都让出CPU
            Thread::yield();
        return (count = ++temp);
    }
    int value() {
        Guard<FastMutex> g(lock);
        return count;
    }
    void cancel() {
        Guard<FastMutex> g(lock);
        canceled = true;
    }
    bool isCanceled() {
        Guard<FastMutex> g(lock);
        return canceled;
    }
    void pause() {
        Guard<FastMutex> g(lock);
        paused = true;
    }
    bool isPaused() {
        Guard<FastMutex> g(lock);
        return paused;
    }
};

class Entrance : public Runnable {
    CountedPtr<Count> count;
    CountedPtr<Display> display;
    int number;
    int id;
    bool waitingForCancel;

public:
    Entrance(CountedPtr<Count>& cnt, CountedPtr<Display>& disp, int idn) :
        count(cnt), display(disp), number(0), id(idn), waitingForCancel(false) {}

    void run() {
        while (!count->isPaused()) {
            ++number;
            {
                ostringstream os;
                os << *this << " 总人数: " << count->increment() << endl;
                display->output(os);
            }
            Thread::sleep(100);
        }
        waitingForCancel = true;
        while (!count->isCanceled()) // 等待取消信号
            Thread::sleep(100);
        ostringstream os;
        os << "正在终止 " << *this << endl;
        display->output(os);
    }
    int getValue() {
        while (count->isPaused() && !waitingForCancel)
            Thread::sleep(100);
        return number;
    }
    friend ostream& operator<<(ostream& os, const Entrance& e) {
        return os << "入口 " << e.id << ": " << e.number;
    }
};

int main() {
    srand(time(0)); // 初始化随机数生成器
    cout << "请按<ENTER>键退出" << endl;
    CountedPtr<Count> count(new Count);
    vector<Entrance*> v;
    CountedPtr<Display> display(new Display);
    const int SZ = 5;
    try {
        ThreadedExecutor executor;
        for (int i = 0; i < SZ; i++) {
            Entrance* task = new Entrance(count, display, i);
            executor.execute(task);            
            v.push_back(task); // 保存任务指针
        }
        cin.get(); // 等待用户按<Enter>键
        count->pause(); // 停止任务计数
        int sum = 0;
        vector<Entrance*>::iterator it = v.begin();
        while (it != v.end()) {
            sum += (*it)->getValue();
            ++it;
        }
        ostringstream os;
        os << "总人数: " << count.value() << std::endl
           << "所有入口人数之和: " << sum << std::endl;
        display->output(os);
        count->cancel(); // 使线程退出
    } catch (Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
