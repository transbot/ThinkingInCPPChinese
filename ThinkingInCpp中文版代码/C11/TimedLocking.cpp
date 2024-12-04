//: C11:TimedLocking.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʱ����
//{L} ZThread
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"

using namespace ZThread;

class TimedLocking {
    Mutex lock;
public:
    void f() {
        Guard<Mutex, TimedLockedScope<500> > g(lock); // ...
    }
};

int main() {
    TimedLocking t;
    t.f();
} ///:~
