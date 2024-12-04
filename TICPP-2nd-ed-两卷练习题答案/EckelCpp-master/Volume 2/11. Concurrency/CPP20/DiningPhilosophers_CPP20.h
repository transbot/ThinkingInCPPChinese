//: C11:DiningPhilosophers_CPP20.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#ifndef DININGPHILOSOPHERS_H
#define DININGPHILOSOPHERS_H

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
#include <thread>
#include <sstream>
#include <atomic>
#include "Display_CPP20.h"


// �����ࣺ��ʾһ�����ӣ���ѧ����Ҫͬʱ�����������Ӳ��ܳԷ�
class Chopstick {
    std::mutex lock;                        // �����������ڱ����Կ��ӵķ���
    std::condition_variable notTaken;       // ��������������֪ͨ�ȴ�����ѧ�ҿ����Ƿ����
    bool taken = false;                     // ��ǿ����Ƿ��Ѿ���ռ��

public:
    // ���캯������ʼ������Ϊδ��ռ��״̬
    Chopstick() = default;

    // take()��������ѧ�ҳ����������
    void take() {
        std::unique_lock<std::mutex> lk(lock);  // ��ȡ��������ȷ���̰߳�ȫ
        while (taken) {                         // ��������Ѿ���ռ�ã��ȴ�
            notTaken.wait(lk);                  // �ȴ�����������ֱ�����ӿ���
        }
        taken = true;                           // ��ǿ����ѱ�ռ��
    }

    // drop()��������ѧ�ҷ��¿���
    void drop() {
        std::unique_lock<std::mutex> lk(lock);  // ��ȡ��������ȷ���̰߳�ȫ
        taken = false;                          // ��ǿ������ͷ�
        notTaken.notify_one();                  // ֪ͨ�ȴ�����ѧ�ҿ������ڿ���
    }
};

// ��ѧ���ࣺ��ʾһ����ѧ�ң�����˼�����ÿ��ӡ��Է��ͷſ���
class Philosopher : public std::enable_shared_from_this<Philosopher> {
    Chopstick& left;                            // ��ߵĿ���
    Chopstick& right;                           // �ұߵĿ���
    int id;                                     // ��ѧ�ҵı��
    int ponderFactor;                           // ˼��ʱ����������
    std::shared_ptr<Display> display;           // ���������Ϣ��Display����
    std::atomic<bool> should_stop{false};       // �жϱ�־λ

public:
    // �����жϱ�־λ
    void request_stop() {
        should_stop.store(true);
    }

    // ���캯������ʼ����ѧ�ҵ����ҿ��ӡ���š�˼�����Ӻ���ʾ����
    Philosopher(Chopstick& l, Chopstick& r, 
                std::shared_ptr<Display> disp, 
                int ident, int ponder)
        : left(l), right(r), id(ident), ponderFactor(ponder),
          display(disp) {}

    // ���������˼����Է�ʱ�䣨�Ժ���Ϊ��λ��
    int randSleepTime() {
        if (ponderFactor == 0) return 0;           // �������Ϊ0������0
        return (rand() % ponderFactor + 1) * 250;  // �������ʱ��
    }

    // �����Ϣ����ʾ����
    void output(std::string s) {
        std::ostringstream os;
        os << *this << " " << s << std::endl;   // ��������ַ���
        display->output(os);                    // ����Ϣ�������ʾ����
    }

    // run()��������ѧ�ҵ���Ϊѭ��
    void run() {
        try {
            while (!should_stop.load()) {  // ����Ƿ��յ��ж�����
                output("����˼��...");
                std::this_thread::sleep_for(std::chrono::milliseconds(randSleepTime())); // ���˼��һ��ʱ��

                // ���ˣ�׼���ÿ���
                output("���ұߵĿ���");
                right.take();
                output("����ߵĿ���");
                left.take();

                output("�Է�");
                std::this_thread::sleep_for(std::chrono::milliseconds(randSleepTime()));

                // ���극�����¿���
                right.drop();
                left.drop();
            }
            output("��ѧ�� " + std::to_string(id) + " �˳�");
        } catch (const std::exception& e) {
            output(e.what());  // ��������쳣
        }
    }

    // ����<<�����������������ѧ�ҵ���Ϣ
    friend std::ostream& operator<<(std::ostream& os, const Philosopher& p) {
        return os << "��ѧ�� " << p.id;  // �����ѧ�ҵı��
    }

    // ������ѧ���̵߳ķ���
    void start() {
        std::thread([self = this->shared_from_this()] {
            self->run();
        }).detach();  // �����̣߳������������
    }
};
#endif // DININGPHILOSOPHERS_H ///:~

