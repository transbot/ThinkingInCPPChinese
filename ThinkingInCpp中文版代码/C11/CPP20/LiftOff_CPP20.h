// C11:LiftOff_CPP20.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#ifndef LIFTOFF_H
#define LIFTOFF_H

#include <iostream>
#include "Runnable_CPP20.h"
#include <thread> // ����ģ����ʱ
#include <mutex>  // ����ͬ�����

// LiftOff��̳���Runnable��ʵ����һ�������𵹼�ʱ����
class LiftOff : public Runnable {
private:
    int countDown; // ����ʱ����
    int id;        // �����ʶ��
    static std::mutex coutMutex; // ��̬������������ͬ��std::cout

public:
    // ���캯������ʼ������ʱ�����������ʶ��
    LiftOff(int count, int ident = 0) : countDown(count), id(ident) {}
    // ������������ӡ������ɵ���Ϣ
    ~LiftOff() override {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << id << " ���" << std::endl;
        
    }
    // ʵ��run������ִ�е���ʱ����
    void run() override {
        while(countDown--) {
            {
                std::lock_guard<std::mutex> lock(coutMutex);
                std::cout << id << ":" << countDown << std::endl; // ��ӡ��ǰ����ʱ
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // ģ����ʱ
        }
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "���!" << std::endl; // ����ʱ��������ӡ�����Ϣ
        }
    }
};

// ��ʼ����̬��Ա����
std::mutex LiftOff::coutMutex;

#endif // LIFTOFF_H  ///:~