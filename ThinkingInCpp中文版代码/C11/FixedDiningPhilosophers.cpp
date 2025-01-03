//: C11:FixedDiningPhilosophers.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 没有死锁的就餐哲学家问题
//{L} ZThread
#include <ctime>
#include "DiningPhilosophers.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

int main(int argc, char* argv[]) {
    srand(time(0)); // 初始化随机数生成器
    int ponder = argc > 1 ? atoi(argv[1]) : 5;
    cout << "请按<ENTER>键退出" << endl;
    enum { SZ = 5 };
    try {
        CountedPtr<Display> d(new Display);
        ThreadedExecutor executor;
        Chopstick c[SZ];
        for(int i = 0; i < SZ; i++) {
            if(i < (SZ - 1)) {
                executor.execute(new Philosopher(c[i], c[i + 1], d, i, ponder));
            } else {
                executor.execute(new Philosopher(c[0], c[i], d, i, ponder));
            }
        }
        cin.get();
        executor.interrupt();
        executor.wait();
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
