//: C05:Urand.h {-bor}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Unique randomizer.
#ifndef URAND_H
#define URAND_H
#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <ctime>
using std::size_t;
using std::bitset;

template<size_t UpperBound> class Urand {
  bitset<UpperBound> used;
public:
  Urand() { srand(time(0)); } // Randomize
  size_t operator()(); // The "generator" function
};

template<size_t UpperBound>
inline size_t Urand<UpperBound>::operator()() {
  if(used.count() == UpperBound)
    used.reset();  // Start over (clear bitset)
  size_t newval;
  while(used[newval = rand() % UpperBound])
    ; // Until unique value is found
  used[newval] = true;
  return newval;
}
#endif // URAND_H ///:~
