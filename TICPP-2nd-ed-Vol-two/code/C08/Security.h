//: C08:Security.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#ifndef SECURITY_H
#define SECURITY_H
#include <iostream>

class Security {
public:
  virtual ~Security() {}
};

class Stock : public Security {};
class Bond : public Security {};

class Investment : public Security {
public:
  void special() {
    std::cout << "special Investment function" <<std::endl;
  }
};

class Metal : public Investment {};
#endif // SECURITY_H ///:~
