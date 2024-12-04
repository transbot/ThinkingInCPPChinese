//: C11:TimedLocking_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��unique_lock����ȡһ��timed_mutex��������ָ��ʱ���ڻ�ȡ��
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <stdexcept>

class TimedLocking {
    std::timed_mutex mtx;
public:
    void f() {
        std::unique_lock<std::timed_mutex> lock(mtx, std::defer_lock);
        const auto timeout = std::chrono::milliseconds(500);

        if (!lock.try_lock_for(timeout)) {
            // ��ʱ�����׳�����ʱ �쳣
            throw std::runtime_error("500ms��δ�����");
        }

        // ��ʼ�ٽ�������
        // ...
        // �����ٽ�������
    }
};

int main() {
    TimedLocking t;
    try {
        t.f();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}