//: C11:GuardedEvenGenerator_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��std::lock_guardģ��򻯻�������ʹ��
#include <iostream>
#include <thread>
#include <mutex> // �����׼���еĻ�����
#include "EvenChecker_CPP20.h"

class MutexEvenGenerator : public Generator {
    unsigned int currentEvenValue;
    std::mutex lock; // ʹ��std::mutex���ZThread::Mutex
public:
    MutexEvenGenerator() : currentEvenValue(0) {}
    ~MutexEvenGenerator() {
        std::cout << "~MutexEvenGenerator" << std::endl;
    }
    int nextValue() {
        std::lock_guard<std::mutex> guard(lock); // lock_guard��һ��RAII����
        ++currentEvenValue;
        std::this_thread::yield(); // ��׼���е�yield
        ++currentEvenValue;
        return currentEvenValue;
    }
};
/*
// ԭʼ�ඨ��
class MutexEvenGenerator : public Generator {
    unsigned int currentEvenValue;
    std::mutex lock; // ʹ��std::mutex���ZThread::Mutex
public:
    MutexEvenGenerator() : currentEvenValue(0) {}
    ~MutexEvenGenerator() {
        std::cout << "~MutexEvenGenerator" << std::endl;
    }
    int nextValue() {
        lock.lock(); // �ֶ���ȡ��
        ++currentEvenValue;
        std::this_thread::yield(); // ��׼���е�yield�����ڼӿ�ʧ���ٶȣ������ʧ�ܵĻ���
        ++currentEvenValue;
        int rval = currentEvenValue;
        lock.unlock(); // �ֶ��ͷ���
        return rval;
    }
}; */

int main() {
    EvenChecker::test<MutexEvenGenerator>();
} ///:~
