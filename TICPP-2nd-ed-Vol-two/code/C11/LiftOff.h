//: C11:LiftOff.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Demonstration of the Runnable interface.
#ifndef LIFTOFF_H
#define LIFTOFF_H
#include <iostream>
#include "zthread/Runnable.h"

class LiftOff : public ZThread::Runnable {
  int countDown;
  int id;
public:
  LiftOff(int count, int ident = 0) :
    countDown(count), id(ident) {}
  ~LiftOff() {
    std::cout << id << " completed" << std::endl;
  }
  void run() {
    while(countDown--)
      std::cout << id << ":" << countDown << std::endl;
    std::cout << "Liftoff!" << std::endl;
  }
};
#endif // LIFTOFF_H ///:~
