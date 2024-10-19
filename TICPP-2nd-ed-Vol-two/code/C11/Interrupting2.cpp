//: C11:Interrupting2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Interrupting a thread blocked
// with a synchronization guard.
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
using namespace ZThread;
using namespace std;

class BlockedMutex {
  Mutex lock;
public:
  BlockedMutex() {
    lock.acquire();
  }
  void f() {
    Guard<Mutex> g(lock);
    // This will never be available
  }
};

class Blocked2 : public Runnable {
  BlockedMutex blocked;
public:
  void run() {
    try {
      cout << "Waiting for f() in BlockedMutex" << endl;
      blocked.f();
    } catch(Interrupted_Exception& e) {
      cerr << e.what() << endl;
      // Exit the task
    }
  }
};

int main(int argc, char* argv[]) {
  try {
    Thread t(new Blocked2);
    t.interrupt();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
