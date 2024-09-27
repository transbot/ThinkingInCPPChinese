//: C11:YieldingTask.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Suggesting when to switch threads with yield().
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

class YieldingTask : public Runnable {
  int countDown;
  int id;
public:
  YieldingTask(int ident = 0) : countDown(5), id(ident) {}
  ~YieldingTask() {
    cout << id << " completed" << endl;
  }
  friend ostream&
  operator<<(ostream& os, const YieldingTask& yt) {
    return os << "#" << yt.id << ": " << yt.countDown;
  }
  void run() {
    while(true) {
      cout << *this << endl;
      if(--countDown == 0) return;
      Thread::yield();
    }
  }
};

int main() {
  try {
    ThreadedExecutor executor;
    for(int i = 0; i < 5; i++)
      executor.execute(new YieldingTask(i));
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
