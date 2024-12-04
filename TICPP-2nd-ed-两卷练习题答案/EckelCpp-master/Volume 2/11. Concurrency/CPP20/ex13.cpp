/* 创建Runnable的两个子类，一个子类的run()启动并调用wait()。
另一个子类的run()应捕获第一个Runnable对象的引用。
它的run()应该在经过一定秒数后，为第一个线程调用signal()，使第一个线程打印一条消息。 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <iostream>
#include "Runnable_CPP20.h"


class WaitRunnable : public Runnable {
    std::mutex mtx;
    std::condition_variable cv;
    bool ready = false;

public:
    void wait() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return ready; });
        std::cout << "WaitRunnable: 收到信号!" << std::endl;
    }

    void signal() {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
        cv.notify_all();
    }

    void run() override {
        std::cout << "WaitRunnable: 开始等待..." << std::endl;
        wait();
    }
};

class SignalRunnable : public Runnable {
    WaitRunnable& waitRunnable;

public:
    SignalRunnable(WaitRunnable& wr) : waitRunnable(wr) {}

    void run() override {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // 等待一定秒数
        std::cout << "SignalRunnable: 发送信号..." << std::endl;
        waitRunnable.signal();
    }
};

int main() {
    WaitRunnable waitRunnable;
    SignalRunnable signalRunnable(waitRunnable);

    std::thread waitThread(&WaitRunnable::run, &waitRunnable);
    std::thread signalThread(&SignalRunnable::run, &signalRunnable);

    waitThread.join();
    signalThread.join();

    return 0;
}
