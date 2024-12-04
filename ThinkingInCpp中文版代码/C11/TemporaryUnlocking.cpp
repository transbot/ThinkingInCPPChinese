//: C11:TemporaryUnlocking.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʱ������һ��Guard
//{L} ZThread
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
using namespace ZThread;

class TemporaryUnlocking {
    Mutex lock;
public:
    void f() {
        Guard<Mutex> g(lock);
        // ��ȡ��
        // ...
        {
            Guard<Mutex, UnlockedScope> h(g);
            // �ͷ���
            // ...
            // ��ȡ��
        } 
        // ...
        // �ͷ���
    } 
};

int main() {
    TemporaryUnlocking t;
    t.f();
} ///:~
