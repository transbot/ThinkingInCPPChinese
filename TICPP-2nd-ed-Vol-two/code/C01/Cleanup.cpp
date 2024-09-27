//: C01:Cleanup.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Exceptions clean up complete objects only.
#include <iostream>
using namespace std;

class Trace {
  static int counter;
  int objid;
public:
  Trace() {
    objid = counter++;
    cout << "constructing Trace #" << objid << endl;
    if(objid == 3) throw 3;
  }
  ~Trace() {
    cout << "destructing Trace #" << objid << endl;
  }
};

int Trace::counter = 0;

int main() {
  try {
    Trace n1;
    // Throws exception:
    Trace array[5];
    Trace n2;  // Won't get here.
  } catch(int i) {
    cout << "caught " << i << endl;
  }
} ///:~
