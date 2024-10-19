//: C02:Rational.h {-xo}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
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
