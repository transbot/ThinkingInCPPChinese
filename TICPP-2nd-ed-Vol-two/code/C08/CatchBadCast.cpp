//: C08:CatchBadCast.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <typeinfo>
#include "Security.h"
using namespace std;

int main() {
  Metal m;
  Security& s = m;
  try {
    Investment& c = dynamic_cast<Investment&>(s);
    cout << "It's an Investment" << endl;
  } catch(bad_cast&) {
    cout << "s is not an Investment type" << endl;
  }
  try {
    Bond& b = dynamic_cast<Bond&>(s);
    cout << "It's a Bond" << endl;
  } catch(bad_cast&) {
    cout << "It's not a Bond type" << endl;
  }
} ///:~
