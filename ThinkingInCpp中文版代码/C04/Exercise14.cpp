//: C04:Exercise14.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <fstream>
#include <iostream>
#include <sstream>
#include "../require.h"
using namespace std;

#define d(a) cout << #a " ==\t" << a << endl;

void tellPointers(fstream& s) {
  d(s.tellp());
  d(s.tellg());
  cout << endl;
}
void tellPointers(stringstream& s) {
  d(s.tellp());
  d(s.tellg());
  cout << endl;
}
int main() {
  fstream in("Exercise14.cpp");
  assure(in, "Exercise14.cpp");
  in.seekg(10);
  tellPointers(in);
  in.seekp(20);
  tellPointers(in);
  stringstream memStream("Here is a sentence.");
  memStream.seekg(10);
  tellPointers(memStream);
  memStream.seekp(5);
  tellPointers(memStream);
} ///:~
