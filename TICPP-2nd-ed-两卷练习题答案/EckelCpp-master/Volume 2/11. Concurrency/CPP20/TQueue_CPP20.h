//: C11:TQueue_CPP20.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#ifndef TQUEUE_H
#define TQUEUE_H

#include <deque>
#include <mutex>
#include <condition_variable>

template<class T>
class TQueue {
    std::mutex mtx;
    std::condition_variable cond;
    std::deque<T> data;

public:
    TQueue() = default;

    // 将元素添加到队列
    void put(T item) {
        std::lock_guard<std::mutex> lock(mtx);
        data.push_back(std::move(item));
        cond.notify_one(); // 通知等待的线程
    }

    // 从队列中获取元素
    T get() {
        std::unique_lock<std::mutex> lock(mtx);
        cond.wait(lock, [this] { return !data.empty(); }); // 等待直到队列不为空
        T returnVal = std::move(data.front());
        data.pop_front();
        return returnVal;
    }
};

#endif // TQUEUE_H
