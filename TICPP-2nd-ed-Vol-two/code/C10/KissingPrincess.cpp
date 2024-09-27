//: C10:KissingPrincess.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <iostream>
using namespace std;

class Creature {
  bool isFrog;
public:
  Creature() : isFrog(true) {}
  void greet() {
    if(isFrog)
      cout << "Ribbet!" << endl;
    else
      cout << "Darling!" << endl;
  }
  void kiss() { isFrog = false; }
};

int main() {
  Creature creature;
  creature.greet();
  creature.kiss();
  creature.greet();
} ///:~
