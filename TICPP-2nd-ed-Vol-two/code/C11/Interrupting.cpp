//: C11:Interrupting.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Interrupting a blocked thread.
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

class Blocked : public Runnable {
public:
  void run() {
    try {
      Thread::sleep(1000);
      cout << "Waiting for get() in run():";
      cin.get();
    } catch(Interrupted_Exception&) {
      cout << "Caught Interrupted_Exception" << endl;
      // Exit the task
    }
  }
};

int main(int argc, char* argv[]) {
  try {
    Thread t(new Blocked);
    if(argc > 1)
      Thread::sleep(1100);
    t.interrupt();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
