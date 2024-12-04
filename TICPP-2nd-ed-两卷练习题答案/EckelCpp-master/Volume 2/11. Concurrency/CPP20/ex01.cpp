/* 从Runnable派生出一个类并重写run()函数。在run()内打印一条消息，然后调用sleep()。
重复上述过程三次，然后从run()返回。在构造函数中显示一条启动消息，在任务终止时显示一条关闭消息。
创建该类型的几个线程对象，运行它们以查看会发生什么。
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "Runnable_CPP20.h"

using namespace std;

// 从Runnable派生出一个类Task
class Task : public Runnable {
    int id; // 任务ID

public:
    // 构造函数，打印启动消息
    Task(int id) : id(id) {
        cout << "任务 " << id << " 启动" << endl;
    }

    // 重写run()函数
    void run() override {
        for (int i = 0; i < 3; ++i) {
            cout << "任务 " << id << " 正在执行第 " << (i + 1) << " 次" << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }

    // 析构函数，打印关闭消息
    ~Task() override {
        cout << "任务 " << id << " 关闭" << endl;
    }
};

// 主函数，创建并运行多个任务
int main() {
    // 创建多个 Task 对象并运行它们
    Task t1(1), t2(2), t3(3);
    thread th1(&Task::run, &t1);
    thread th2(&Task::run, &t2);
    thread th3(&Task::run, &t3);

    // 等待所有线程完成
    th1.join();
    th2.join();
    th3.join();

    return 0;
}
