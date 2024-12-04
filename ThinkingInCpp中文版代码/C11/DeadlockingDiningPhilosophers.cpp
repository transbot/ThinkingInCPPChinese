//: C11:DeadlockingDiningPhilosophers.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Dining Philosophers with Deadlock.
//{L} ZThread
#include <ctime>
#include "DiningPhilosophers.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

int main(int argc, char* argv[]) {
  srand(time(0)); // Seed the random number generator
  int ponder = argc > 1 ? atoi(argv[1]) : 5;
  cout << "Press <ENTER> to quit" << endl;
  enum { SZ = 5 };
  try {
    CountedPtr<Display> d(new Display);
    ThreadedExecutor executor;
    Chopstick c[SZ];
    for(int i = 0; i < SZ; i++) {
      executor.execute(
        new Philosopher(c[i], c[(i+1) % SZ], d, i,ponder));
    }
    cin.get();
    executor.interrupt();
    executor.wait();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
