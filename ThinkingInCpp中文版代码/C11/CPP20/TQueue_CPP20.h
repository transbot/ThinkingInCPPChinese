//: C11:TQueue_CPP20.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

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

    // ��Ԫ����ӵ�����
    void put(T item) {
        std::lock_guard<std::mutex> lock(mtx);
        data.push_back(std::move(item));
        cond.notify_one(); // ֪ͨ�ȴ����߳�
    }

    // �Ӷ����л�ȡԪ��
    T get() {
        std::unique_lock<std::mutex> lock(mtx);
        cond.wait(lock, [this] { return !data.empty(); }); // �ȴ�ֱ�����в�Ϊ��
        T returnVal = std::move(data.front());
        data.pop_front();
        return returnVal;
    }
};

#endif // TQUEUE_H
