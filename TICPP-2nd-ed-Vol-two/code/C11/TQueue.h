//: C11:TQueue.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#ifndef TQUEUE_H
#define TQUEUE_H
#include <deque>
#include "zthread/Thread.h"
#include "zthread/Condition.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"

template<class T> class TQueue {
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
