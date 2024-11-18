//: C07:BankTeller_CPP20.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��һ��queue�Լ�ģ��Ķ��̴߳�������ģ���й�Աϵͳ
// ʹ�����ִ�C++�������Եİ汾
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

public:
    Teller(queue<Customer>& cq) : customers(cq), ttime(0), busy(false) {}
    Teller& operator=(const Teller& rv) {
        customers = rv.customers;
        current = rv.current;
        ttime = rv.ttime;
        busy = rv.busy;
        return *this;
    }
    bool isBusy() const { return busy; }

    // run()�ǳ������Ҫ�߼�
    void run(bool recursion = false) {
        if (!recursion)
            ttime = SLICE;
        int servtime = current.getTime();
        if (servtime > ttime) {
            servtime -= ttime;
            current.setTime(servtime);
            busy = true; // ���ڴ���ǰ�˿�
            return;
        }
        if (servtime < ttime) {
            ttime -= servtime;
            if (!customers.empty()) {
                current = customers.front();
                customers.pop(); // �Ƴ���ǰ�˿�
                busy = true;
                run(true); // �ݹ����
            }
            return;
        }
        if (servtime == ttime) {
            // �����굱ǰ�˿ͣ�����Ϊ����״̬��
            current = Customer(0);
            busy = false;
            return; // ��ǰʱ��Ƭ����
        }
    }
};

// �̳��Է����ܱ�����ʵ��
class CustomerQ : public queue<Customer> {
public:
    friend ostream& operator<<(ostream& os, const CustomerQ& cd) {
        copy(cd.c.begin(), cd.c.end(), ostream_iterator<Customer>(os, ""));
        return os;
    }
};

int main() {
    CustomerQ customers;
    list<shared_ptr<Teller>> tellers;
    mt19937 gen(random_device{}()); // �����������
    uniform_int_distribution<int> customerDist(0, 4); // �˿͵��������ֲ�
    uniform_int_distribution<int> serviceDist(1, 15); // ����ʱ�������ֲ�

    auto startTime = chrono::high_resolution_clock::now(); // ��¼��ʼʱ��

    // ��ʼ������һ����Ա
    tellers.push_back(make_shared<Teller>(customers));

    // ��������5���ģ��
    while (chrono::duration_cast<chrono::seconds>(chrono::high_resolution_clock::now() - startTime).count() < 5) {
        // ��queue�������������Ĺ˿ͣ�����ʱ�����
        for (int i = 0; i < customerDist(gen); ++i) {
            customers.push(Customer(serviceDist(gen)));
        }
        cout << '{' << tellers.size() << '}'
             << customers << endl;

        // �ù�Ա����queue�еĹ˿�
        for (auto& teller : tellers) {
            teller->run();
        }
        cout << '{' << tellers.size() << '}'
             << customers << endl;

        // ���queue̫��������һ����Ա
        if (customers.size() > 2 * tellers.size()) {
            tellers.push_back(make_shared<Teller>(customers));
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

    return 0;
}