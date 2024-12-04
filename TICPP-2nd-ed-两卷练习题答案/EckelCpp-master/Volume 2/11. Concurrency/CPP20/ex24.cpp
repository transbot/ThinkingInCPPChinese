
#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <exception>
#include <chrono>
#include <memory>
#include <sstream>
#include <atomic>
#include <queue>
#include "Display_CPP20.h"

using namespace std;

// 筷子类：表示一根筷子，哲学家需要同时持有两根筷子才能吃饭
class Chopstick {
    std::mutex lock;                        // 互斥锁，用于保护对筷子的访问
    bool taken = false;                     // 标记筷子是否已经被占用

public:
    // 构造函数，初始化筷子为未被占用状态
    Chopstick() = default;

    // take()方法：哲学家尝试拿起筷子
    void take() {
        lock.lock();
        taken = true;
    }

    // drop()方法：哲学家放下筷子
    void drop() {
        taken = false;
        lock.unlock();
    }
};

// 筷子箱类，用于管理所有筷子
class ChopstickBox {
    queue<shared_ptr<Chopstick>> chopsticks;  // 存放所有筷子的队列
    mutex mtx;                                // 互斥锁，用于保护对筷子箱的访问

public:
    // 构造函数，初始化筷子箱
    ChopstickBox(int count) {
        for (int i = 0; i < count; ++i) {
            chopsticks.push(make_shared<Chopstick>());
        }
    }

    // 获取两根可用的筷子
    vector<shared_ptr<Chopstick>> getTwo() {
        unique_lock<mutex> lock(mtx);
        while (chopsticks.size() < 2) {
            lock.unlock();
            this_thread::sleep_for(chrono::milliseconds(100));  // 等待筷子可用
            lock.lock();
        }
        vector<shared_ptr<Chopstick>> result;
        result.push_back(chopsticks.front());
        chopsticks.pop();
        result.push_back(chopsticks.front());
        chopsticks.pop();
        return result;
    }

    // 归还两根筷子
    void putTwo(vector<shared_ptr<Chopstick>> two) {
        lock_guard<mutex> lock(mtx);
        chopsticks.push(two[0]);
        chopsticks.push(two[1]);
    }
};

// 哲学家类
class Philosopher : public enable_shared_from_this<Philosopher> {
    shared_ptr<ChopstickBox> box;             // 公共筷子箱
    vector<shared_ptr<Chopstick>> chopsticks; // 哲学家持有的筷子
    int id;                                   // 哲学家的编号
    int ponderFactor;                         // 思考时间的随机因子
    shared_ptr<Display> display;              // 用于输出信息的Display对象
    atomic<bool> should_stop{false};          // 中断标志位

public:
    // 设置中断标志位
    void request_stop() {
        should_stop.store(true);
    }

    // 构造函数，初始化哲学家的编号、思考因子和显示对象
    Philosopher(shared_ptr<ChopstickBox> b, 
                shared_ptr<Display> disp, 
                int ident, int ponder)
        : box(b), id(ident), ponderFactor(ponder), display(disp) {}

    // 生成随机的思考或吃饭时间（以毫秒为单位）
    int randSleepTime() {
        if (ponderFactor == 0) return 0;           // 如果因子为0，返回0
        return (rand() % ponderFactor + 1) * 250;  // 生成随机时间
    }

    // 输出信息到显示对象
    void output(string s) {
        ostringstream os;
        os << *this << " " << s << endl;          // 构建输出字符串
        display->output(os);                      // 将信息输出到显示对象
    }

    // run()方法：哲学家的行为循环
    void run() {
        try {
            while (!should_stop.load()) {         // 检查是否收到中断请求
                output("正在思考...");
                this_thread::sleep_for(chrono::milliseconds(randSleepTime())); // 随机思考一段时间

                // 饿了，准备拿筷子
                output("拿两根筷子");
                chopsticks = box->getTwo();

                output("吃饭");
                this_thread::sleep_for(chrono::milliseconds(randSleepTime()));

                // 吃完饭，放下筷子
                output("放回两根筷子");
                box->putTwo(chopsticks);
                chopsticks.clear();
            }
            output("哲学家 " + to_string(id) + " 退出");
        } catch (const exception& e) {
            output(e.what());                    // 捕获并输出异常
        }
    }

    // 重载<<操作符，用于输出哲学家的信息
    friend ostream& operator<<(ostream& os, const Philosopher& p) {
        return os << "哲学家 " << p.id;          // 输出哲学家的编号
    }

    // 运行哲学家线程的方法
    void start() {
        thread([self = this->shared_from_this()] {
            self->run();
        }).detach();                             // 分离线程，让其独立运行
    }
};

int main() {
    auto display = make_shared<Display>();

    // 创建一个筷子箱，里面有5根筷子（等于哲学家的数量）
    auto box = make_shared<ChopstickBox>(5);

    // 创建并启动5个哲学家
    vector<shared_ptr<Philosopher>> philosophers;
    for (int i = 0; i < 5; ++i) {
        auto philosopher = make_shared<Philosopher>(box, display, i, 5);
        philosophers.push_back(philosopher);
        philosopher->start();
    }

    this_thread::sleep_for(chrono::seconds(10)); // 让哲学家们思考和吃饭一段时间

    // 中断哲学家线程
    for (auto& philosopher : philosophers) {
        philosopher->request_stop();
    }

    this_thread::sleep_for(chrono::seconds(2)); // 给线程一些时间来优雅地退出

    return 0;
}
