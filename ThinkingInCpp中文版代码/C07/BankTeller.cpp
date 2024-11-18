//: C07:BankTeller.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��һ��queue�Լ�ģ��Ķ��̴߳�������ģ���й�Աϵͳ
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
using namespace std;

class Customer {
    int serviceTime;
public:
    Customer() : serviceTime(0) {}
    Customer(int tm) : serviceTime(tm) {}
    int getTime() { return serviceTime; }
    void setTime(int newtime) { serviceTime = newtime; }
    friend ostream& operator<<(ostream& os, const Customer& c) {
        return os << '[' << c.serviceTime << ']';
    }
};

class Teller {
    queue<Customer>& customers;
    Customer current;
    enum { SLICE = 5 }; // ʱ��Ƭ��С
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
    bool isBusy() { return busy; }
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
    list<Teller> tellers;
    typedef list<Teller>::iterator TellIt;
    tellers.push_back(Teller(customers));
    srand(time(0)); // ��ʼ�������������
    clock_t ticks = clock(); // ��¼��ʼʱ��
    // ��������5���ģ��
    while (clock() < ticks + 5 * CLOCKS_PER_SEC) {
        // ��queue�������������Ĺ˿ͣ�����ʱ�����
        for (int i = 0; i < rand() % 5; i++)
            customers.push(Customer(rand() % 15 + 1));
        cout << '{' << tellers.size() << '}'
             << customers << endl;
        // �ù�Ա����queue�еĹ˿�
        for (TellIt i = tellers.begin();
             i != tellers.end(); i++)
            (*i).run();
        cout << '{' << tellers.size() << '}'
             << customers << endl;
        // ���queue̫��������һ����Ա
        if (customers.size() / tellers.size() > 2)
            tellers.push_back(Teller(customers));
        // ���queue�㹻�̣��Ƴ�һ����Ա
        if (tellers.size() > 1 &&
            customers.size() / tellers.size() < 2)
            for (TellIt i = tellers.begin(); i != tellers.end(); i++)
                if (!(*i).isBusy()) {
                    tellers.erase(i);
                    break; // �˳�ѭ��
                }
    }
} ///:~
