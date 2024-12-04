//: C11:TemporaryUnlocking_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��std::unique_lockʵ����ʱ����
#include <mutex>

class TemporaryUnlocking {
    std::mutex mtx;
public:
    void f() {
        std::unique_lock<std::mutex> lock(mtx);
        // ... �ٽ��� ...

        // ��ʱ����
        lock.unlock();
        // ... ���ٽ���
        lock.lock();

        // ... �ٽ��� ...
    }
};

int main() {
    TemporaryUnlocking t;
    t.f();
} ///:~
