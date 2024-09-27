//: C11:EvenGenerator.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// When threads collide.
//{L} ZThread
#include <iostream>
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

class EvenGenerator : public Generator {
  unsigned int currentEvenValue; // Unsigned can't overflow
public:
  EvenGenerator() { currentEvenValue = 0; }
  ~EvenGenerator() { cout << "~EvenGenerator" << endl; }
  int nextValue() {
    ++currentEvenValue; // Danger point here!
    ++currentEvenValue;
    return currentEvenValue;
  }
};

int main() {
  EvenChecker::test<EvenGenerator>();
} ///:~
