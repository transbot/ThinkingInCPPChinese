//: C08:Security.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
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
