/* ����Runnable���������࣬һ�������run()����������wait()��
��һ�������run()Ӧ�����һ��Runnable��������á�
����run()Ӧ���ھ���һ��������Ϊ��һ���̵߳���signal()��ʹ��һ���̴߳�ӡһ����Ϣ�� */

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
        std::cout << "WaitRunnable: �յ��ź�!" << std::endl;
    }

    void signal() {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
        cv.notify_all();
    }

    void run() override {
        std::cout << "WaitRunnable: ��ʼ�ȴ�..." << std::endl;
        wait();
    }
};

class SignalRunnable : public Runnable {
    WaitRunnable& waitRunnable;

public:
    SignalRunnable(WaitRunnable& wr) : waitRunnable(wr) {}

    void run() override {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // �ȴ�һ������
        std::cout << "SignalRunnable: �����ź�..." << std::endl;
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
