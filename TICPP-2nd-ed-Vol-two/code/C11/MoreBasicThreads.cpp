//: C11:MoreBasicThreads.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Adding more threads.
//{L} ZThread
#include <iostream>
#include "LiftOff.h"
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

int main() {
  const int SZ = 5;
  try {
    for(int i = 0; i < SZ; i++)
      Thread t(new LiftOff(10, i));
    cout << "Waiting for LiftOff" << endl;
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
