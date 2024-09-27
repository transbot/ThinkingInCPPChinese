//: C11:NoThread.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include "LiftOff.h"

int main() {
  LiftOff launch(10);
  launch.run();
} ///:~
