//: C11:DiningPhilosophers.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �Ͳ���ѧ��������ඨ��
#ifndef DININGPHILOSOPHERS_H
#define DININGPHILOSOPHERS_H

#include <string>
#include <iostream>
#include <cstdlib>
#include "zthread/Condition.h"
#include "zthread/Guard.h"
#include "zthread/Mutex.h"
#include "zthread/Thread.h"
#include "Display.h"

// �����ࣺ��ʾһҪ���ӣ���ѧ����Ҫͬʱ�����������Ӳ��ܳԷ�
class Chopstick {
    ZThread::Mutex lock;          // �����������ڱ����Կ��ӵķ���
    ZThread::Condition notTaken;  // ��������������֪ͨ�ȴ�����ѧ�ҿ����Ƿ����
    bool taken;                   // ��ǿ����Ƿ��ѱ�ռ��

public:
    // ���캯������ʼ������Ϊδ��ռ��״̬
    Chopstick() : notTaken(lock), taken(false) {}

    // take()��������ѧ�ҳ����������
    void take() {
        ZThread::Guard<ZThread::Mutex> g(lock);   // ��ȡ��������ȷ���̰߳�ȫ
        while (taken) {                           // ��������Ѿ���ռ�ã��ȴ�
            notTaken.wait();                      // �ȴ�����������ֱ�����ӿ���
        }
        taken = true;                             // ��ǿ����ѱ�ռ��
    }

    // drop()��������ѧ�ҷ��¿���
    void drop() {
        ZThread::Guard<ZThread::Mutex> g(lock);  // ��ȡ��������ȷ���̰߳�ȫ
        taken = false;                           // ��ǿ������ͷ�
        notTaken.signal();                       // ֪ͨ�ȴ�����ѧ�ҿ������ڿ���
    }
};

// ��ѧ���ࣺ��ʾһ����ѧ�ң�����˼�����ÿ��ӡ��Է��ͷſ���
class Philosopher : public ZThread::Runnable {
    Chopstick& left;                             // ��ߵĿ���
    Chopstick& right;                            // �ұߵĿ���
    int id;                                      // ��ѧ�ҵı��
    int ponderFactor;                            // ˼��ʱ����������
    ZThread::CountedPtr<Display> display;        // ���������Ϣ��Display����

    // ���������˼����Է�ʱ�䣨�Ժ���Ϊ��λ��
    int randSleepTime() {
        if (ponderFactor == 0) return 0;         // �������Ϊ0������0
        return rand() / (RAND_MAX / ponderFactor) * 250;  // �������ʱ��
    }

    // �����Ϣ����ʾ����
    void output(std::string s) {
        std::ostringstream os;
        os << *this << " " << s << std::endl;   // ��������ַ���
        display->output(os);                    // ����Ϣ�������ʾ����
    }

public:
    // ���캯������ʼ����ѧ�ҵ����ҿ��ӡ���š�˼�����Ӻ���ʾ����
    Philosopher(Chopstick& l, Chopstick& r, 
                ZThread::CountedPtr<Display>& disp, 
                int ident, int ponder)
        : left(l), right(r), id(ident), ponderFactor(ponder),
          display(disp) {}

    // run()��������ѧ�ҵ���Ϊѭ��
    virtual void run() {
        try {
            while (!ZThread::Thread::interrupted()) {    // ����Ƿ��յ��ж�����
                output("˼��");                          // ���˼����Ϣ
                ZThread::Thread::sleep(randSleepTime()); // ���˼��һ��ʱ��

                // ���ˣ�׼���ÿ���
                output("���ұߵĿ���");
                right.take();  // ���������ұߵĿ���

                output("����ߵĿ���");
                left.take();   // ����������ߵĿ���

                output("�Է�");  // ����Է���Ϣ
                ZThread::Thread::sleep(randSleepTime());  // ����Է�һ��ʱ��

                // ���극�����¿���
                right.drop();  // �����ұߵĿ���
                left.drop();   // ������ߵĿ���
            }
        } catch (ZThread::Synchronization_Exception& e) {
            output(e.what());  // �������ͬ���쳣
        }
    }

    // ����<<�����������������ѧ�ҵ���Ϣ
    friend std::ostream& operator<<(std::ostream& os, const Philosopher& p) {
        return os << "��ѧ�� " << p.id;  // �����ѧ�ҵı��
    }
};

#endif // DININGPHILOSOPHERS_H ///:~