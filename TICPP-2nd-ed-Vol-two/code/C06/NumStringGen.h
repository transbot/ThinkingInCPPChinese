//: C06:NumStringGen.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// A random number generator that produces
// strings representing floating-point numbers.
#ifndef NUMSTRINGGEN_H
#define NUMSTRINGGEN_H
#include <cstdlib>
#include <string>

class NumStringGen {
  const int sz; // Number of digits to make
public:
  NumStringGen(int ssz = 5) : sz(ssz) {}
  std::string operator()() {
    std::string digits("0123456789");
    const int ndigits = digits.size();
    std::string r(sz, ' ');
    // Don't want a zero as the first digit
    r[0] = digits[std::rand() % (ndigits - 1)] + 1;
    // Now assign the rest
    for(int i = 1; i < sz; ++i)
      if(sz >= 3 && i == sz/2)
        r[i] = '.'; // Insert a decimal point
      else
        r[i] = digits[std::rand() % ndigits];
    return r;
  }
};
#endif // NUMSTRINGGEN_H ///:~
