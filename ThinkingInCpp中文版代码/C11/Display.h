//: C11:Display.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ֹ ostream ��ͻ
#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <sstream>
#include "zthread/Mutex.h"
#include "zthread/Guard.h"

class Display {
    // �������߳��й���һ�������Ķ���
    ZThread::Mutex iolock;

public:
    void output(std::ostringstream& os) {
        ZThread::Guard<ZThread::Mutex> g(iolock);
        std::cout << os.str();
    }
};
#endif // DISPLAY_H ///:~
