//: C11:TemporaryUnlocking_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用std::unique_lock实现临时解锁
#include <mutex>

class TemporaryUnlocking {
    std::mutex mtx;
public:
    void f() {
        std::unique_lock<std::mutex> lock(mtx);
        // ... 临界区 ...

        // 临时解锁
        lock.unlock();
        // ... 非临界区
        lock.lock();

        // ... 临界区 ...
    }
};

int main() {
    TemporaryUnlocking t;
    t.f();
} ///:~
