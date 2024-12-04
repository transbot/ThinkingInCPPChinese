//: C11:TQueue.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#ifndef TQUEUE_H
#define TQUEUE_H
#include <deque>
#include "zthread/Thread.h"
#include "zthread/Condition.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"

template<class T>
class TQueue {
    ZThread::Mutex lock;
    ZThread::Condition cond;
    std::deque<T> data;
public:
    TQueue() : cond(lock) {}
    void put(T item) {
        ZThread::Guard<ZThread::Mutex> g(lock);
        data.push_back(item);
        cond.signal();
    }
    T get() {
        ZThread::Guard<ZThread::Mutex> g(lock);
        while(data.empty())
            cond.wait();
        T returnVal = data.front();
        data.pop_front();
        return returnVal;
    }
};
#endif // TQUEUE_H ///:~
