//: C05:BearCorner2.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Illustrates policy classes.
#include <iostream>
#include "BearCorner.h"
using namespace std;

// Policy classes (require a static doAction() function):
class Feed {
public:
  static const char* doAction() { return "Feeding"; }
};

class Stuff {
public:
  static const char* doAction() { return "Stuffing"; }
};

// The Guest template (uses a policy and a traits class)
template<class Guest, class Action,
         class traits = GuestTraits<Guest> >
class BearCorner {
  Guest theGuest;
  typedef typename traits::beverage_type beverage_type;
  typedef typename traits::snack_type snack_type;
  beverage_type bev;
  snack_type snack;
public:
  BearCorner(const Guest& g) : theGuest(g) {}
  void entertain() {
    cout << Action::doAction() << " " << theGuest
         << " with " << bev
         << " and " << snack << endl;
  }
};

int main() {
  Boy cr;
  BearCorner<Boy, Feed> pc1(cr);
  pc1.entertain();
  Bear pb;
  BearCorner<Bear, Stuff> pc2(pb);
  pc2.entertain();
} ///:~
