//: C10:MulticastCommand.cpp {RunByHand}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Decoupling event management with the Command pattern.
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// Framework for running tasks:
class Task {
public:
  virtual void operation() = 0;
};

class TaskRunner {
  static vector<Task*> tasks;
  TaskRunner() {} // Make it a Singleton
  TaskRunner& operator=(TaskRunner&); // Disallowed
  TaskRunner(const TaskRunner&); // Disallowed
  static TaskRunner tr;
public:
  static void add(Task& t) { tasks.push_back(&t); }
  static void run() {
    vector<Task*>::iterator it = tasks.begin();
    while(it != tasks.end())
      (*it++)->operation();
  }
};

TaskRunner TaskRunner::tr;
vector<Task*> TaskRunner::tasks;

class EventSimulator {
  clock_t creation;
  clock_t delay;
public:
  EventSimulator() : creation(clock()) {
    delay = CLOCKS_PER_SEC/4 * (rand() % 20 + 1);
    cout << "delay = " << delay << endl;
  }
  bool fired() {
    return clock() > creation + delay;
  }
};

// Something that can produce asynchronous events:
class Button {
  bool pressed;
  string id;
  EventSimulator e; // For demonstration
public:
  Button(string name) : pressed(false), id(name) {}
  void press() { pressed = true; }
  bool isPressed() {
    if(e.fired()) press(); // Simulate the event
    return pressed;
  }
  friend ostream&
  operator<<(ostream& os, const Button& b) {
    return os << b.id;
  }
};

// The Command object
class CheckButton : public Task {
  Button& button;
  bool handled;
public:
  CheckButton(Button & b) : button(b), handled(false) {}
  void operation() {
    if(button.isPressed() && !handled) {
      cout << button << " pressed" << endl;
      handled = true;
    }
  }
};

// The procedures that perform the main processing. These
// need to be occasionally "interrupted" in order to
// check the state of the buttons or other events:
void procedure1() {
  // Perform procedure1 operations here.
  // ...
  TaskRunner::run(); // Check all events
}

void procedure2() {
  // Perform procedure2 operations here.
  // ...
  TaskRunner::run(); // Check all events
}

void procedure3() {
  // Perform procedure3 operations here.
  // ...
  TaskRunner::run(); // Check all events
}

int main() {
  srand(time(0)); // Randomize
  Button b1("Button 1"), b2("Button 2"), b3("Button 3");
  CheckButton cb1(b1), cb2(b2), cb3(b3);
  TaskRunner::add(cb1);
  TaskRunner::add(cb2);
  TaskRunner::add(cb3);
  cout << "Control-C to exit" << endl;
  while(true) {
    procedure1();
    procedure2();
    procedure3();
  }
} ///:~
