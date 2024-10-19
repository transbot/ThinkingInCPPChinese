//: C08:Security.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
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
