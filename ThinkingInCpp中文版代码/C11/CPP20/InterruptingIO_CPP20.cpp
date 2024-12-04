//: C11:InterruptingIO_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �ִ�C++�����ִ��I/O�ڼ��˳�
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<bool> terminate_thread(false);

void io_task() {
    while (!terminate_thread.load()) {
        // ģ��I/O����
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "����ִ��I/O����" << std::endl;

        // ���ڼ���Ƿ���Ҫ��ֹ�߳�
        if (terminate_thread.load()) {
            std::cout << "������ִֹ��I/O���߳�" << std::endl;
            break;
        }
    }
}

int main() {
    std::thread t(io_task);
    std::this_thread::sleep_for(std::chrono::seconds(2));  // ģ�����̵߳���������    
    std::cout << "�����߳���ֹ" << std::endl;
    terminate_thread.store(true);  // ������ֹ����

    t.join();  // �ȴ��߳̽���

    std::cout << "�߳�����ֹ" << std::endl;
    return 0;
}
