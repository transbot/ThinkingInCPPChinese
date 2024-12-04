#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <mutex>
#include <condition_variable>

class Timer {
    std::atomic<bool> active;       // ���ڿ��ƶ�ʱ���ļ���״̬
    std::thread timerThread;        // ��ʱ���߳�
    std::mutex mtx;                 // ������������ʱ��״̬
    std::condition_variable cv;     // ������������֪ͨ��ʱ��ֹͣ

public:
    Timer() : active(false) {}

    ~Timer() {
        stop();  // ������������ȷ����ʱ��ֹͣ
    }

    // һ���Զ�ʱ����ֻ����һ��
    void once(int interval, std::function<void()> task) {
        if (active.load()) return;  // �����ʱ���Ѿ����ֱ�ӷ���
        active = true;
        timerThread = std::thread([=]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));  // �ȴ�ָ��ʱ��
            if (active.load()) {  // ��鶨ʱ���Ƿ���Ȼ����
                task();  // ִ������
            }
            stop();  // ������ɺ�ֹͣ��ʱ��
        });
    }

    // ���ڴ����Ķ�ʱ��
    void periodic(int interval, std::function<void()> task) {
        if (active.load()) return;  // �����ʱ���Ѿ����ֱ�ӷ���
        active = true;
        timerThread = std::thread([=]() {
            while (active.load()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));  // �ȴ�ָ��ʱ��
                if (active.load()) {  // ��鶨ʱ���Ƿ���Ȼ����
                    task();  // ִ������
                }
            }
        });
    }

    // ֹͣ��ʱ��
    void stop() {
        active = false;
        cv.notify_all();
        if (timerThread.joinable()) {
            timerThread.join();  // �ȴ���ʱ���߳̽���
        }
    }
};

#endif // TIMER_H
