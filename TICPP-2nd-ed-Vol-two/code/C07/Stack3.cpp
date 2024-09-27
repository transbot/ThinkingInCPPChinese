//: C07:Stack3.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Using a vector as a stack; modified Stack1.cpp.
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ifstream in("Stack3.cpp");
  vector<string> textlines;
  string line;
  while(getline(in, line))
    textlines.push_back(line + "\n");
  while(!textlines.empty()) {
    cout << textlines.back();
    textlines.pop_back();
  }
} ///:~
