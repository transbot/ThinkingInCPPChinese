
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

// �����ࣺ��ʾһ�����ӣ���ѧ����Ҫͬʱ�����������Ӳ��ܳԷ�
class Chopstick {
    std::mutex lock;                        // �����������ڱ����Կ��ӵķ���
    bool taken = false;                     // ��ǿ����Ƿ��Ѿ���ռ��

public:
    // ���캯������ʼ������Ϊδ��ռ��״̬
    Chopstick() = default;

    // take()��������ѧ�ҳ����������
    void take() {
        lock.lock();
        taken = true;
    }

    // drop()��������ѧ�ҷ��¿���
    void drop() {
        taken = false;
        lock.unlock();
    }
};

// �������࣬���ڹ������п���
class ChopstickBox {
    queue<shared_ptr<Chopstick>> chopsticks;  // ������п��ӵĶ���
    mutex mtx;                                // �����������ڱ����Կ�����ķ���

public:
    // ���캯������ʼ��������
    ChopstickBox(int count) {
        for (int i = 0; i < count; ++i) {
            chopsticks.push(make_shared<Chopstick>());
        }
    }

    // ��ȡ�������õĿ���
    vector<shared_ptr<Chopstick>> getTwo() {
        unique_lock<mutex> lock(mtx);
        while (chopsticks.size() < 2) {
            lock.unlock();
            this_thread::sleep_for(chrono::milliseconds(100));  // �ȴ����ӿ���
            lock.lock();
        }
        vector<shared_ptr<Chopstick>> result;
        result.push_back(chopsticks.front());
        chopsticks.pop();
        result.push_back(chopsticks.front());
        chopsticks.pop();
        return result;
    }

    // �黹��������
    void putTwo(vector<shared_ptr<Chopstick>> two) {
        lock_guard<mutex> lock(mtx);
        chopsticks.push(two[0]);
        chopsticks.push(two[1]);
    }
};

// ��ѧ����
class Philosopher : public enable_shared_from_this<Philosopher> {
    shared_ptr<ChopstickBox> box;             // ����������
    vector<shared_ptr<Chopstick>> chopsticks; // ��ѧ�ҳ��еĿ���
    int id;                                   // ��ѧ�ҵı��
    int ponderFactor;                         // ˼��ʱ����������
    shared_ptr<Display> display;              // ���������Ϣ��Display����
    atomic<bool> should_stop{false};          // �жϱ�־λ

public:
    // �����жϱ�־λ
    void request_stop() {
        should_stop.store(true);
    }

    // ���캯������ʼ����ѧ�ҵı�š�˼�����Ӻ���ʾ����
    Philosopher(shared_ptr<ChopstickBox> b, 
                shared_ptr<Display> disp, 
                int ident, int ponder)
        : box(b), id(ident), ponderFactor(ponder), display(disp) {}

    // ���������˼����Է�ʱ�䣨�Ժ���Ϊ��λ��
    int randSleepTime() {
        if (ponderFactor == 0) return 0;           // �������Ϊ0������0
        return (rand() % ponderFactor + 1) * 250;  // �������ʱ��
    }

    // �����Ϣ����ʾ����
    void output(string s) {
        ostringstream os;
        os << *this << " " << s << endl;          // ��������ַ���
        display->output(os);                      // ����Ϣ�������ʾ����
    }

    // run()��������ѧ�ҵ���Ϊѭ��
    void run() {
        try {
            while (!should_stop.load()) {         // ����Ƿ��յ��ж�����
                output("����˼��...");
                this_thread::sleep_for(chrono::milliseconds(randSleepTime())); // ���˼��һ��ʱ��

                // ���ˣ�׼���ÿ���
                output("����������");
                chopsticks = box->getTwo();

                output("�Է�");
                this_thread::sleep_for(chrono::milliseconds(randSleepTime()));

                // ���극�����¿���
                output("�Ż���������");
                box->putTwo(chopsticks);
                chopsticks.clear();
            }
            output("��ѧ�� " + to_string(id) + " �˳�");
        } catch (const exception& e) {
            output(e.what());                    // ��������쳣
        }
    }

    // ����<<�����������������ѧ�ҵ���Ϣ
    friend ostream& operator<<(ostream& os, const Philosopher& p) {
        return os << "��ѧ�� " << p.id;          // �����ѧ�ҵı��
    }

    // ������ѧ���̵߳ķ���
    void start() {
        thread([self = this->shared_from_this()] {
            self->run();
        }).detach();                             // �����̣߳������������
    }
};

int main() {
    auto display = make_shared<Display>();

    // ����һ�������䣬������5�����ӣ�������ѧ�ҵ�������
    auto box = make_shared<ChopstickBox>(5);

    // ����������5����ѧ��
    vector<shared_ptr<Philosopher>> philosophers;
    for (int i = 0; i < 5; ++i) {
        auto philosopher = make_shared<Philosopher>(box, display, i, 5);
        philosophers.push_back(philosopher);
        philosopher->start();
    }

    this_thread::sleep_for(chrono::seconds(10)); // ����ѧ����˼���ͳԷ�һ��ʱ��

    // �ж���ѧ���߳�
    for (auto& philosopher : philosophers) {
        philosopher->request_stop();
    }

    this_thread::sleep_for(chrono::seconds(2)); // ���߳�һЩʱ�������ŵ��˳�

    return 0;
}
