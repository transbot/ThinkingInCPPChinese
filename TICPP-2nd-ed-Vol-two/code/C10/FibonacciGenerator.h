//: C10:FibonacciGenerator.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#ifndef FIBONACCIGENERATOR_H
#define FIBONACCIGENERATOR_H

class FibonacciGenerator {
  int n;
  int val[2];
public:
  FibonacciGenerator() : n(0) { val[0] = val[1] = 0; }
  int operator()() {
    int result = n > 2 ? val[0] + val[1] : n > 0 ? 1 : 0;
    ++n;
    val[0] = val[1];
    val[1] = result;
    return result;
  }
  int count() { return n; }
};
#endif // FIBONACCIGENERATOR_H ///:~
