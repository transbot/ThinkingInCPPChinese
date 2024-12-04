//: C11:LiftOff.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 演示Runnable接口
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
        std::cout << id << " 完成" << std::endl;
    }
    void run() {
        while(countDown--) 
            std::cout << id << ":" << countDown << std::endl;
        std::cout << "点火!" << std::endl;
    }
};
#endif // LIFTOFF_H ///:~
