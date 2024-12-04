// ��дC07:BankTeller_CPP20.cpp��ʹ���������̶߳�����ģ���̡߳�

#include <iostream>
#include <queue>
#include <list>
#include <memory>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include <iterator>
#include <functional>
#include <atomic>
#include <mutex>

using namespace std;

class Customer {
    int serviceTime;
public:
    Customer() : serviceTime(0) {}
    Customer(int tm) : serviceTime(tm) {}
    int getTime() const { return serviceTime; }
    void setTime(int newtime) { serviceTime = newtime; }
    friend ostream& operator<<(ostream& os, const Customer& c) {
        return os << '[' << c.serviceTime << ']';
    }
};

class Teller {    
    queue<Customer>& customers;
    Customer current;
    static constexpr int SLICE = 5; // ʱ��Ƭ��С
    int ttime; // ��ǰʱ��Ƭ��ʣ��ʱ��
    bool busy; // ��Ա�Ƿ����ڷ���˿�
    std::atomic<bool>& stopFlag;
    std::mutex mtx;

public:
    Teller(queue<Customer>& cq, std::atomic<bool>& stop) : customers(cq), ttime(0), busy(false), stopFlag(stop) {}
    Teller& operator=(const Teller& rv) {
        customers = rv.customers;
        current = rv.current;
        ttime = rv.ttime;
        busy = rv.busy;
        return *this;
    }
    bool isBusy() const { return busy; }

    // run()�ǳ������Ҫ�߼�
    void run() {
        while (!stopFlag.load()) {
            std::unique_lock<std::mutex> lock(mtx);
            if (!busy && !customers.empty()) {
                current = customers.front();
                customers.pop();
                busy = true;
                ttime = SLICE;
            }
            lock.unlock();
            
            if (busy) {
                int servtime = current.getTime();
                if (servtime > ttime) {
                    servtime -= ttime;
                    current.setTime(servtime);
                    busy = true;
                } else if (servtime <= ttime) {
                    if (servtime < ttime) {
                        ttime -= servtime;
                        if (!customers.empty()) {
                            lock.lock();
                            current = customers.front();
                            customers.pop();
                            busy = true;
                            lock.unlock();
                        } else {
                            busy = false;
                        }
                    } else {
                        current = Customer(0);
                        busy = false;
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};

// �̳��Է����ܱ�����ʵ��
class CustomerQ : public queue<Customer> {
public:
    friend ostream& operator<<(ostream& os, const CustomerQ& cd) {
        std::copy(cd.c.begin(), cd.c.end(), ostream_iterator<Customer>(os, ""));
        return os;
    }
};

int main() {
    CustomerQ customers;
    list<shared_ptr<Teller>> tellers;
    list<std::thread> threads;
    std::atomic<bool> stopFlag(false);
    mt19937 gen(random_device{}()); // �����������
    uniform_int_distribution<int> customerDist(0, 4); // �˿͵��������ֲ�
    uniform_int_distribution<int> serviceDist(1, 15); // ����ʱ�������ֲ�

    auto startTime = chrono::high_resolution_clock::now(); // ��¼��ʼʱ��

    // ��ʼ������һ����Ա
    auto teller = make_shared<Teller>(customers, stopFlag);
    tellers.push_back(teller);
    threads.emplace_back(&Teller::run, teller);

    // ��������5���ģ��
    while (chrono::duration_cast<chrono::seconds>(chrono::high_resolution_clock::now() - startTime).count() < 5) {
        // ��queue�������������Ĺ˿ͣ�����ʱ�����
        for (int i = 0; i < customerDist(gen); ++i) {
            customers.push(Customer(serviceDist(gen)));
        }
        cout << '{' << tellers.size() << '}' << customers << endl;

        // ���queue̫��������һ����Ա
        if (customers.size() > 2 * tellers.size()) {
            auto newTeller = make_shared<Teller>(customers, stopFlag);
            tellers.push_back(newTeller);
            threads.emplace_back(&Teller::run, newTeller);
        }

        // ���queue�㹻�̣��Ƴ�һ����Ա
        if (tellers.size() > 1 && customers.size() < 2 * tellers.size()) {
            for (auto it = tellers.begin(); it != tellers.end(); ++it) {
                if (!(*it)->isBusy()) {
                    tellers.erase(it);
                    break; // �˳�ѭ��
                }
            }
        }

        this_thread::sleep_for(chrono::milliseconds(100)); // ģ��ʱ��Ƭ
    }

    // ֹͣ���й�Ա�߳�
    stopFlag.store(true);
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
