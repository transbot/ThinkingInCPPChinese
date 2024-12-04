// ��Ӹ����Process��ʵ����ʹ��Ӧ�ò��׹�������������һ�㡣

// �������߳�Э��
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <atomic>
#include <vector>

class Car {
    std::mutex mtx;
    std::condition_variable condition;
    int layer; // ����
public:
    Car() : layer(0) {}

    void waxed() {
        std::lock_guard<std::mutex> lock(mtx);
        layer++; // ����һ����
        condition.notify_all();
    }

    void buffed() {
        std::lock_guard<std::mutex> lock(mtx);
        layer--; // �׹�ȥ��һ����
        condition.notify_all();
    }

    void waitForWaxing(int targetLayer) { // �ȴ��������
        std::unique_lock<std::mutex> lock(mtx);
        condition.wait(lock, [this, targetLayer] { return layer == targetLayer; });
    }

    void waitForBuffing(int targetLayer) { // �ȴ��׹����
        std::unique_lock<std::mutex> lock(mtx);
        condition.wait(lock, [this, targetLayer] { return layer == targetLayer; });
    }
};

class Process {
    Car& car;
    std::atomic<bool>& interrupted;
    int layer;
    bool isWaxOn;
public:
    Process(Car& c, std::atomic<bool>& interrupt, int l, bool waxOn)
        : car(c), interrupted(interrupt), layer(l), isWaxOn(waxOn) {}

    void operator()() {
        try {
            while (!interrupted.load()) {
                if (isWaxOn) {
                    std::cout << "���ڴ����� " << layer << " ��!" << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    car.waxed();
                    car.waitForBuffing(layer);
                } else {
                    car.waitForWaxing(layer);
                    std::cout << "�����׹�� " << layer << " ��!" << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    car.buffed();
                }
            }
        } catch (...) {
            // ���������쳣����ֹ����
        }
        if (isWaxOn) {
            std::cout << "�����������̵� " << layer << " ��" << std::endl;
        } else {
            std::cout << "�����׹���̵� " << layer << " ��" << std::endl;
        }
    }
};

int main() {
    std::cout << "�밴<Enter>���˳�" << std::endl;
    try {
        Car car;
        std::atomic<bool> interrupted(false);
        std::vector<std::thread> threads;

        for (int i = 1; i <= 3; ++i) { // Ϊ����������׹ⴴ���߳�
            threads.emplace_back(Process(car, interrupted, i, true)); // �����߳�
            threads.emplace_back(Process(car, interrupted, i, false)); // �׹��߳�
        }

        // �ȴ��û���<Enter>��
        std::cin.get();
        interrupted.store(true);

        for (auto& t : threads) {
            t.join();
        }
    } catch (const std::exception& e) {
        std::cerr << "�쳣: " << e.what() << std::endl;
    }
    std::cout << "���ڹر�..." << std::endl;
    return 0;
}
