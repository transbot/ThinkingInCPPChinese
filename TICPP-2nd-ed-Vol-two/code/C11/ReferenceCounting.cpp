//: C11:ReferenceCounting.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// A CountedPtr prevents too-early destruction.
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/CountedPtr.h"
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
  CountedPtr<Count> count;
public:
  Incrementer(const CountedPtr<Count>& c ) : count(c) {}
  void run() {
    for(int n = 100; n > 0; n--) {
      Thread::sleep(250);
      count->increment();
    }
  }
};

int main() {
  CountedPtr<Count> count(new Count);
  try {
    Thread t0(new Incrementer(count));
    Thread t1(new Incrementer(count));
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
