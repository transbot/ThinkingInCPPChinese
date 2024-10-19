//: C11:EvenChecker.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#ifndef EVENCHECKER_H
#define EVENCHECKER_H
#include <iostream>
#include "zthread/CountedPtr.h"
#include "zthread/Thread.h"
#include "zthread/Cancelable.h"
#include "zthread/ThreadedExecutor.h"

class Generator : public ZThread::Cancelable {
  bool canceled;
public:
  Generator() : canceled(false) {}
  virtual int nextValue() = 0;
  void cancel() { canceled = true; }
  bool isCanceled() { return canceled; }
};

class EvenChecker : public ZThread::Runnable {
  ZThread::CountedPtr<Generator> generator;
  int id;
public:
  EvenChecker(ZThread::CountedPtr<Generator>& g, int ident)
  : generator(g), id(ident) {}
  ~EvenChecker() {
    std::cout << "~EvenChecker " << id << std::endl;
  }
  void run() {
    while(!generator->isCanceled()) {
      int val = generator->nextValue();
      if(val % 2 != 0) {
        std::cout << val << " not even!" << std::endl;
        generator->cancel(); // Cancels all EvenCheckers
      }
    }
  }
  // Test any type of generator:
  template<typename GenType> static void test(int n = 10) {
    std::cout << "Press Control-C to exit" << std::endl;
    try {
      ZThread::ThreadedExecutor executor;
      ZThread::CountedPtr<Generator> gp(new GenType);
      for(int i = 0; i < n; i++)
        executor.execute(new EvenChecker(gp, i));
    } catch(ZThread::Synchronization_Exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }
};
#endif // EVENCHECKER_H ///:~
