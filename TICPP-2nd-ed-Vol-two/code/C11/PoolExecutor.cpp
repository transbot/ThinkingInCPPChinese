//: C11:PoolExecutor.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
//{L} ZThread
#include <iostream>
#include "zthread/PoolExecutor.h"
#include "LiftOff.h"
using namespace ZThread;
using namespace std;

int main() {
  try {
    // Constructor argument is minimum number of threads:
    PoolExecutor executor(5);
    for(int i = 0; i < 5; i++)
      executor.execute(new LiftOff(10, i));
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
