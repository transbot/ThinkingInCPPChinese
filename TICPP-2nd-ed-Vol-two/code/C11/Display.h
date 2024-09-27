//: C11:Display.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Prevents ostream collisions.
#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <sstream>
#include "zthread/Mutex.h"
#include "zthread/Guard.h"

class Display { // Share one of these among all threads
  ZThread::Mutex iolock;
public:
  void output(std::ostringstream& os) {
    ZThread::Guard<ZThread::Mutex> g(iolock);
    std::cout << os.str();
  }
};
#endif // DISPLAY_H ///:~
