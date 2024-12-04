// C11:FixedDiningPhilosophers_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 存在死锁可能的就餐哲学家问题
// 对原程序进行了修改，采用了资源层次化方法防止死锁。
// 具体地说，我们确保哲学家总是按照相同的顺序拿起筷子。
// 例如，每个哲学家先拿编号小的筷子，再拿编号大的筷子。
// 通过这种方法，可以避免循环等待，从而避免死锁。

#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "DiningPhilosophers_CPP20.h"
using namespace std;

int main(int argc, char* argv[]) {
    // 初始化随机数生成器
    srand(static_cast<unsigned>(time(0)));

    // 获取命令行参数，设置哲学家思考的时间因子
    int ponder = (argc > 1) ? atoi(argv[1]) : 5;
    cout << "请按<ENTER>键退出" << endl;

    // 定义常量，表示哲学家的数量
    const int NUM_PHILOSOPHERS = 5;

    try {        
        // 创建Display对象
        auto display = make_shared<Display>();

        // 创建筷子数组
        vector<Chopstick> chopsticks(NUM_PHILOSOPHERS);

        // 创建哲学家数组，并启动他们的线程
        /* 为了避免死锁，哲学家们将按照统一的顺序拿筷子。具体地说，他们总是先拿编号较小的筷子，再拿编号较大的筷子。这意味着：
             编号为 0 的哲学家将先拿 chopsticks[0] 再拿 chopsticks[1]。
             编号为 1 的哲学家将先拿 chopsticks[1] 再拿 chopsticks[2]。
             编号为 2 的哲学家将先拿 chopsticks[2] 再拿 chopsticks[3]。
             编号为 3 的哲学家将先拿 chopsticks[3] 再拿 chopsticks[4]。
             编号为 4 的哲学家将先拿 chopsticks[0] 再拿 chopsticks[4]（因为 4 % 5 = 0）。
           通过这种方式，每个哲学家总是先拿编号较小的筷子，这样就可以避免形成循环等待的情况，从而防止死锁。 */
           
        vector<shared_ptr<Philosopher>> philosophers;
        for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
            // 所有哲学家先拿编号小的筷子，再拿编号大的筷子
            auto philosopher = make_shared<Philosopher>(
                chopsticks[min(i, (i + 1) % NUM_PHILOSOPHERS)],
                chopsticks[max(i, (i + 1) % NUM_PHILOSOPHERS)],
                display, i, ponder
            );
            philosopher->start();
            philosophers.push_back(philosopher);
        }

        // 等待用户按下Enter键
        cin.get();

        // 请求所有哲学家线程停止
        for (auto& philosopher : philosophers) {
            philosopher->request_stop();
        }

        // 主线程等待一段时间，确保所有哲学家线程有足够的时间退出
        this_thread::sleep_for(chrono::seconds(1));

        // 输出结束信息
        cout << "所有哲学家已退出" << endl;

    } catch (const exception& e) {
        cerr << "异常: " << e.what() << endl;
    }

    return 0;
}
