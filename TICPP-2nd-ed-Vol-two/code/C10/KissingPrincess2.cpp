//: C10:KissingPrincess2.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// The State pattern.
#include <iostream>
#include <string>
using namespace std;

class Creature {
  class State {
  public:
    virtual string response() = 0;
  };
  class Frog : public State {
  public:
    string response() { return "Ribbet!"; }
  };
  class Prince : public State {
  public:
    string response() { return "Darling!"; }
  };
  State* state;
public:
  Creature() : state(new Frog()) {}
  void greet() {
    cout << state->response() << endl;
  }
  void kiss() {
    delete state;
    state = new Prince();
  }
};

int main() {
  Creature creature;
  creature.greet();
  creature.kiss();
  creature.greet();
} ///:~
