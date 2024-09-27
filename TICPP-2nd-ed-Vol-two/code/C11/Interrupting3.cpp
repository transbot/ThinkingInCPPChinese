//: C11:Interrupting3.cpp {RunByHand}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// General idiom for interrupting a task.
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

const double PI = 3.14159265358979323846;
const double E = 2.7182818284590452354;

class NeedsCleanup {
  int id;
public:
  NeedsCleanup(int ident) : id(ident) {
    cout << "NeedsCleanup " << id << endl;
  }
  ~NeedsCleanup() {
    cout << "~NeedsCleanup " << id << endl;
  }
};

class Blocked3 : public Runnable {
  volatile double d;
public:
  Blocked3() : d(0.0) {}
  void run() {
    try {
      while(!Thread::interrupted()) {
        point1:
        NeedsCleanup n1(1);
        cout << "Sleeping" << endl;
        Thread::sleep(1000);
        point2:
        NeedsCleanup n2(2);
        cout << "Calculating" << endl;
        // A time-consuming, non-blocking operation:
        for(int i = 1; i < 100000; i++)
          d = d + (PI + E) / (double)i;
      }
      cout << "Exiting via while() test" << endl;
    } catch(Interrupted_Exception&) {
      cout << "Exiting via Interrupted_Exception" << endl;
    }
  }
};

int main(int argc, char* argv[]) {
  if(argc != 2) {
    cerr << "usage: " << argv[0]
      << " delay-in-milliseconds" << endl;
    exit(1);
  }
  int delay = atoi(argv[1]);
  try {
    Thread t(new Blocked3);
    Thread::sleep(delay);
    t.interrupt();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
