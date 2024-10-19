//: C02:Date1.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// A first pass at Date.h.
#ifndef DATE1_H
#define DATE1_H
#include <string>

class Date {
public:
  // A struct to hold elapsed time:
  struct Duration {
    int years;
    int months;
    int days;
    Duration(int y, int m, int d)
    : years(y), months(m), days(d) {}
  };
  Date();
  Date(int year, int month, int day);
  Date(const std::string&);
  int getYear() const;
  int getMonth() const;
  int getDay() const;
  std::string toString() const;
   friend bool operator<(const Date&, const Date&);
   friend bool operator>(const Date&, const Date&);
   friend bool operator<=(const Date&, const Date&);
   friend bool operator>=(const Date&, const Date&);
   friend bool operator==(const Date&, const Date&);
   friend bool operator!=(const Date&, const Date&);
  friend Duration duration(const Date&, const Date&);
};
#endif // DATE1_H ///:~
