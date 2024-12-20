//: C10:CommandPattern.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
#include <vector>
using namespace std;

class Command {
public:
  virtual void execute() = 0;
};

class Hello : public Command {
public:
  void execute() { cout << "Hello "; }
};

class World : public Command {
public:
  void execute() { cout << "World! "; }
};

class IAm : public Command {
public:
  void execute() { cout << "I'm the command pattern!"; }
};

// An object that holds commands:
class Macro {
  vector<Command*> commands;
public:
  void add(Command* c) { commands.push_back(c); }
  void run() {
    vector<Command*>::iterator it = commands.begin();
    while(it != commands.end())
      (*it++)->execute();
  }
};

int main() {
  Macro macro;
  macro.add(new Hello);
  macro.add(new World);
  macro.add(new IAm);
  macro.run();
} ///:~
