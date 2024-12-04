/* 创建一个“忙等待”的示例（参见11.6.2节）。一个线程睡眠一会儿后，将一个标志设置为true。
 第二个线程在一个while循环内监视该标志（这就是“忙等待”），当标志变为true时，将其重新设置为false，并向控制台报告变化。
 注意程序在“忙等待”中浪费了多少时间，并创建程序的另一个版本，使用wait()而不是“忙等待”。
 额外练习：运行某个性能探查器（profiler）来显示每种情况下的CPU占用时间。 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
bool flag = false;

void setFlagAfterSleep() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
        std::lock_guard<std::mutex> lock(mtx);
        flag = true;
    }
    cv.notify_all();
}

void wait() {
    auto start = std::chrono::high_resolution_clock::now();
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return flag; });
    flag = false;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "标志变为true，等待时间: " << elapsed.count() << " 秒" << std::endl;
}

int main() {
    std::thread t1(setFlagAfterSleep);
    std::thread t2(wait);

    t1.join();
    t2.join();

    return 0;
}
