//: C11:Incrementer.cpp {RunByHand}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Destroying objects while threads are still
// running will cause serious problems.
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

class Count {
  enum { SZ = 100 };
  int n[SZ];
public:
  void increment() {
    for(int i = 0; i < SZ; i++)
      n[i]++;
  }
};

class Incrementer : public Runnable {
  Count* count;
public:
  Incrementer(Count* c) : count(c) {}
  void run() {
    for(int n = 100; n > 0; n--) {
      Thread::sleep(250);
      count->increment();
    }
  }
};

int main() {
  cout << "This will cause a segmentation fault!" << endl;
  Count count;
  try {
    Thread t0(new Incrementer(&count));
    Thread t1(new Incrementer(&count));
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
