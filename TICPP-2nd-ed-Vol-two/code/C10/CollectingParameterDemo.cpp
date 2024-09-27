//: C10:CollectingParameterDemo.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CollectingParameter : public vector<string> {};

class Filler {
public:
  void f(CollectingParameter& cp) {
    cp.push_back("accumulating");
  }
  void g(CollectingParameter& cp) {
    cp.push_back("items");
  }
  void h(CollectingParameter& cp) {
    cp.push_back("as we go");
  }
};

int main() {
  Filler filler;
  CollectingParameter cp;
  filler.f(cp);
  filler.g(cp);
  filler.h(cp);
  vector<string>::iterator it = cp.begin();
  while(it != cp.end())
    cout << *it++ << " ";
  cout << endl;
} ///:~
