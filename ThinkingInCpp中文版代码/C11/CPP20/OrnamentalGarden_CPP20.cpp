//: C11:OrnamentalGarden_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �����ģ���У���԰�Ĺ����ϣ��֪��ÿ���ж�����ͨ�����������԰��
// ÿ����ڶ���һ����תդ�Ż��������͵ļ�����������תդ�ż���������
// �������һ������԰���������Ĺ��������

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include "Display_CPP20.h"

class Count {
    std::mutex lock;
    int count;
    std::atomic<bool> paused, canceled;

public:
    Count() : count(0), paused(false), canceled(false) {}

    int increment() {
        std::lock_guard<std::mutex> g(lock);
        int temp = count;
        if (rand() % 2 == 0) {
            std::this_thread::yield(); // ����ʱ���ó�CPU
        }
        return count = ++temp;
    }

    int value() {
        std::lock_guard<std::mutex> g(lock);
        return count;
    }

    void cancel() {
        std::lock_guard<std::mutex> g(lock);
        canceled = true;
    }

    bool isCanceled() const {
        return canceled.load();
    }

    void pause() {
        std::lock_guard<std::mutex> g(lock);
        paused = true;
    }

    bool isPaused() const {
        return paused.load();
    }
};

class Entrance {
    Count& count;
    Display& display;
    int number;
    int id;
    std::atomic<bool> waitingForCancel;

public:
    Entrance(Count& cnt, Display& disp, int idn)
        : count(cnt), display(disp), number(0), id(idn), waitingForCancel(false) {}

    void operator()() {
        while (!count.isPaused()) {
            ++number;
            {
                std::ostringstream os;
                os << *this << " ������: " << count.increment() << std::endl;
                display.output(os);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        waitingForCancel = true;
        while (!count.isCanceled()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        std::ostringstream os;
        os << "������ֹ " << *this << std::endl;
        display.output(os);
    }

    int getValue() {
        while (count.isPaused() && !waitingForCancel.load()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        return number;
    }

    friend std::ostream& operator<<(std::ostream& os, const Entrance& e) {
        return os << "��� " << e.id << ": " << e.number;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));  // ��ʼ�������������
    std::cout << "�밴<ENTER>���˳�" << std::endl;

    Count count;
    Display display;
    const int SZ = 5;
    std::vector<std::thread> threads;
    std::vector<std::unique_ptr<Entrance>> entrances;

    // ��������������߳�
    for (int i = 0; i < SZ; ++i) {
        entrances.push_back(std::make_unique<Entrance>(count, display, i));
        threads.emplace_back(std::ref(*entrances.back()));
    }

    // �ȴ��û���<Enter>��
    std::cin.get();
    count.pause();  // ֹͣ�������

    // ���㲢��ʾ������
    int sum = 0;
    for (auto& entrance : entrances) {
        sum += entrance->getValue();
    }

    std::ostringstream os;
    os << "������: " << count.value() << std::endl
        << "�����������֮��: " << sum << std::endl;
    display.output(os);

    // ȡ��������ڲ��ȴ��߳̽���
    count.cancel();
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    return 0;
}
