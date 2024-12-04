//: C11:Display_CPP20.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ֹ ostream ��ͻ
#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <sstream>
#include <mutex>

class Display {
    // �������߳��й���һ�������Ķ���
    std::mutex iolock;

public:
    void output(std::ostringstream& os) {
        std::lock_guard<std::mutex> g(iolock); // �Զ���ȡ���ͷ���
        std::cout << os.str();
    }
};
#endif // DISPLAY_H ///:~