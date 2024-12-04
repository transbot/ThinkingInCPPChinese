//: C11:WaxOMatic_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �������߳�Э��
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <atomic>

class Car {
    std::mutex mtx;
    std::condition_variable condition;
    bool waxOn;
public:
    Car() : waxOn(false) {}

    void waxed() {
        std::lock_guard<std::mutex> lock(mtx);
        waxOn = true; // ������ɣ�׼�����׹�
        condition.notify_all();
    }

    void buffed() {
        std::lock_guard<std::mutex> lock(mtx);
        waxOn = false; // �׹���ɣ���׼������Ϳһ����
        condition.notify_all();
    }

    void waitForWaxing() { // �ȴ��������
        std::unique_lock<std::mutex> lock(mtx);
        condition.wait(lock, [this] { return waxOn; });
    }

    void waitForBuffing() { // �ȴ��׹����
        std::unique_lock<std::mutex> lock(mtx);
        condition.wait(lock, [this] { return !waxOn; });
    }
};

class WaxOn {
    Car& car;
    std::atomic<bool>& interrupted;
public:
    WaxOn(Car& c, std::atomic<bool>& interrupt) : car(c), interrupted(interrupt) {}

    void operator()() {
        try {
            while (!interrupted.load()) {
                std::cout << "���ڴ���!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                car.waxed();
                car.waitForBuffing();
            }
        } catch (...) {
            // ���������쳣����ֹ����
        }
        std::cout << "������������" << std::endl;
    }
};

class WaxOff {
    Car& car;
    std::atomic<bool>& interrupted;
public:
    WaxOff(Car& c, std::atomic<bool>& interrupt) : car(c), interrupted(interrupt) {}

    void operator()() {
        try {
            while (!interrupted.load()) {
                car.waitForWaxing();
                std::cout << "�����׹�!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                car.buffed();
            }
        } catch (...) {
            // ���������쳣����ֹ����
        }
        std::cout << "�����׹����" << std::endl;
    }
};

int main() {
    std::cout << "�밴<Enter>���˳�" << std::endl;
    try {
        Car car;
        std::atomic<bool> interrupted(false);
        std::thread waxOffThread(WaxOff(car, interrupted));
        std::thread waxOnThread(WaxOn(car, interrupted));

        // �ȴ��û���<Enter>��
        std::cin.get();
        interrupted.store(true);

        waxOnThread.join();
        waxOffThread.join();
    } catch (const std::exception& e) {
        std::cerr << "�쳣: " << e.what() << std::endl;
    }
    std::cout << "���ڹر�..." << std::endl;
    return 0;
}
