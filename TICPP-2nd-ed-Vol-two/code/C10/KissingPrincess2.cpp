//: C10:KissingPrincess2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
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
