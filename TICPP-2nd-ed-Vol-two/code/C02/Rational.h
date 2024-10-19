//: C02:Rational.h {-xo}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iosfwd>

class Rational {
public:
  Rational(int numerator = 0, int denominator = 1);
  Rational operator-() const;
  friend Rational operator+(const Rational&,
                            const Rational&);
  friend Rational operator-(const Rational&,
                            const Rational&);
  friend Rational operator*(const Rational&,
                            const Rational&);
  friend Rational operator/(const Rational&,
                            const Rational&);
  friend std::ostream&
  operator<<(std::ostream&, const Rational&);
  friend std::istream&
  operator>>(std::istream&, Rational&);
  Rational& operator+=(const Rational&);
  Rational& operator-=(const Rational&);
  Rational& operator*=(const Rational&);
  Rational& operator/=(const Rational&);
  friend bool operator<(const Rational&,
                        const Rational&);
  friend bool operator>(const Rational&,
                        const Rational&);
  friend bool operator<=(const Rational&,
                         const Rational&);
  friend bool operator>=(const Rational&,
                         const Rational&);
  friend bool operator==(const Rational&,
                         const Rational&);
  friend bool operator!=(const Rational&,
                         const Rational&);
};
#endif // RATIONAL_H ///:~
