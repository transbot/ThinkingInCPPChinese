//: C11:LiftOff.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// ��ʾRunnable�ӿ�
#ifndef LIFTOFF_H
#define LIFTOFF_H

#include <iostream>
#include "zthread/Runnable.h"

class LiftOff : public ZThread::Runnable {
    int countDown;
    int id;

public:
    LiftOff(int count, int ident = 0) : countDown(count), id(ident) {}
    ~LiftOff() {
        std::cout << id << " ���" << std::endl;
    }
    void run() {
        while(countDown--) 
            std::cout << id << ":" << countDown << std::endl;
        std::cout << "���!" << std::endl;
    }
};
#endif // LIFTOFF_H ///:~
