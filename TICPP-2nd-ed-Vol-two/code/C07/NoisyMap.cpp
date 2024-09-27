//: C07:NoisyMap.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Mapping Noisy to Noisy.
//{L} Noisy
#include <map>
#include "Noisy.h"
using namespace std;

int main() {
  map<Noisy, Noisy> mnn;
  Noisy n1, n2;
  cout << "\n--------" << endl;
  mnn[n1] = n2;
  cout << "\n--------" << endl;
  cout << mnn[n1] << endl;
  cout << "\n--------" << endl;
} ///:~
