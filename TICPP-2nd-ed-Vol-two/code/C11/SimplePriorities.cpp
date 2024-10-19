//: C11:SimplePriorities.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Shows the use of thread priorities.
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

const double pi = 3.14159265358979323846;
const double e = 2.7182818284590452354;

class SimplePriorities : public Runnable {
  int countDown;
  volatile double d; // No optimization
  int id;
public:
  SimplePriorities(int ident=0): countDown(5), id(ident) {}
  ~SimplePriorities() {
    cout << id << " completed" << endl;
  }
  friend ostream&
  operator<<(ostream& os, const SimplePriorities& sp) {
    return os << "#" << sp.id << " priority: "
      << Thread().getPriority()
      << " count: "<< sp.countDown;
  }
  void run() {
    while(true) {
      // An expensive, interruptable operation:
      for(int i = 1; i < 100000; i++)
        d = d + (pi + e) / double(i);
      cout << *this << endl;
      if(--countDown == 0) return;
    }
  }
};

int main() {
  try {
    Thread high(new SimplePriorities);
    high.setPriority(High);
    for(int i = 0; i < 5; i++) {
      Thread low(new SimplePriorities(i));
      low.setPriority(Low);
    }
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
