//: C07:BankTeller.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用一个queue以及模拟的多线程处理来建模银行柜员系统
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
    enum { SLICE = 5 }; // 时间片大小
    int ttime; // 当前时间片的剩余时间
    bool busy; // 柜员是否正在服务顾客

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
            busy = true; // 仍在处理当前顾客
            return;
        }
        if (servtime < ttime) {
            ttime -= servtime;
            if (!customers.empty()) {
                current = customers.front();
                customers.pop(); // 移除当前顾客
                busy = true;
                run(true); // 递归调用
            }
            return;
        }
        if (servtime == ttime) {
            // 处理完当前顾客，设置为空闲状态：
            current = Customer(0);
            busy = false;
            return; // 当前时间片结束
        }
    }
};

// 继承以访问受保护的实现
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
    srand(time(0)); // 初始化随机数生成器
    clock_t ticks = clock(); // 记录开始时间
    // 至少运行5秒的模拟
    while (clock() < ticks + 5 * CLOCKS_PER_SEC) {
        // 在queue中添加随机数量的顾客，服务时间随机
        for (int i = 0; i < rand() % 5; i++)
            customers.push(Customer(rand() % 15 + 1));
        cout << '{' << tellers.size() << '}'
             << customers << endl;
        // 让柜员服务queue中的顾客
        for (TellIt i = tellers.begin();
             i != tellers.end(); i++)
            (*i).run();
        cout << '{' << tellers.size() << '}'
             << customers << endl;
        // 如果queue太长，增加一个柜员
        if (customers.size() / tellers.size() > 2)
            tellers.push_back(Teller(customers));
        // 如果queue足够短，移除一个柜员
        if (tellers.size() > 1 &&
            customers.size() / tellers.size() < 2)
            for (TellIt i = tellers.begin(); i != tellers.end(); i++)
                if (!(*i).isBusy()) {
                    tellers.erase(i);
                    break; // 退出循环
                }
    }
} ///:~
