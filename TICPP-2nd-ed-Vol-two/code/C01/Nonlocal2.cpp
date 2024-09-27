//: C01:Nonlocal2.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Illustrates exceptions.
#include <iostream>
using namespace std;

class Rainbow {
public:
  Rainbow() { cout << "Rainbow()" << endl; }
  ~Rainbow() { cout << "~Rainbow()" << endl; }
};

void oz() {
  Rainbow rb;
  for(int i = 0; i < 3; i++)
    cout << "there's no place like home" << endl;
  throw 47;
}

int main() {
  try {
    cout << "tornado, witch, munchkins..." << endl;
    oz();
  } catch(int) {
    cout << "Auntie Em! I had the strangest dream..."
         << endl;
  }
} ///:~
