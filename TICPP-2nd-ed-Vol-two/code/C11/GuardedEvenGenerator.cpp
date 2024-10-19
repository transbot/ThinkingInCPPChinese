//: C11:GuardedEvenGenerator.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Simplifying mutexes with the Guard template.
//{L} ZThread
#include <iostream>
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
using namespace ZThread;
using namespace std;

class GuardedEvenGenerator : public Generator {
  unsigned int currentEvenValue;
  Mutex lock;
public:
  GuardedEvenGenerator() { currentEvenValue = 0; }
  ~GuardedEvenGenerator() {
    cout << "~GuardedEvenGenerator" << endl;
  }
  int nextValue() {
    Guard<Mutex> g(lock);
    ++currentEvenValue;
    Thread::yield();
    ++currentEvenValue;
    return currentEvenValue;
  }
};

int main() {
  EvenChecker::test<GuardedEvenGenerator>();
} ///:~
