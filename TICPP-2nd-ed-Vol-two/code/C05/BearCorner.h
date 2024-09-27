//: C05:BearCorner.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#ifndef BEARCORNER_H
#define BEARCORNER_H
#include <iostream>
using std::ostream;

// Item classes (traits of guests):
class Milk {
public:
  friend ostream& operator<<(ostream& os, const Milk&) {
    return os << "Milk";
  }
};

class CondensedMilk {
public:
  friend ostream&
  operator<<(ostream& os, const CondensedMilk &) {
    return os << "Condensed Milk";
  }
};

class Honey {
public:
  friend ostream& operator<<(ostream& os, const Honey&) {
    return os << "Honey";
  }
};

class Cookies {
public:
  friend ostream& operator<<(ostream& os, const Cookies&) {
    return os << "Cookies";
  }
};

// Guest classes:
class Bear {
public:
  friend ostream& operator<<(ostream& os, const Bear&) {
    return os << "Theodore";
  }
};

class Boy {
public:
  friend ostream& operator<<(ostream& os, const Boy&) {
    return os << "Patrick";
  }
};

// Primary traits template (empty-could hold common types)
template<class Guest> class GuestTraits;

// Traits specializations for Guest types
template<> class GuestTraits<Bear> {
public:
  typedef CondensedMilk beverage_type;
  typedef Honey snack_type;
};

template<> class GuestTraits<Boy> {
public:
  typedef Milk beverage_type;
  typedef Cookies snack_type;
};
#endif // BEARCORNER_H ///:~
