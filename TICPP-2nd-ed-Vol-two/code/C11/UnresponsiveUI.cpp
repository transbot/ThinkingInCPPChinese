//: C11:UnresponsiveUI.cpp {RunByHand}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Lack of threading produces an unresponsive UI.
//{L} ZThread
#include <iostream>
#include <fstream>
#include <string>
#include "zthread/Thread.h"
using namespace std;
using namespace ZThread;

int main() {
  cout << "Press <Enter> to quit:" << endl;
  ifstream file("UnresponsiveUI.cpp");
  string line;
  while(getline(file, line)) {
    cout << line << endl;
    Thread::sleep(1000); // Time in milliseconds
  }
  // Read input from the console
  cin.get();
  cout << "Shutting down..." << endl;
} ///:~
