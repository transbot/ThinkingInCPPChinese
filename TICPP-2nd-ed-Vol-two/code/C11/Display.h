//: C11:Display.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
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
