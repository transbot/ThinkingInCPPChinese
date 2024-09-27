//: C05:Sortable.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
//{-bor} (Because of bitset in Urand.h)
// Testing template specialization.
#include <cstddef>
#include <iostream>
#include "Sortable.h"
#include "Urand.h"
using namespace std;

#define asz(a) (sizeof a / sizeof a[0])

char* words[] = { "is", "running", "big", "dog", "a", };
char* words2[] = { "this", "that", "theother", };

int main() {
  Sortable<int> is;
  Urand<47> rnd;
  for(size_t i = 0; i < 15; ++i)
    is.push_back(rnd());
  for(size_t i = 0; i < is.size(); ++i)
    cout << is[i] << ' ';
  cout << endl;
  is.sort();
  for(size_t i = 0; i < is.size(); ++i)
    cout << is[i] << ' ';
  cout << endl;

  // Uses the template partial specialization:
  Sortable<string*> ss;
  for(size_t i = 0; i < asz(words); ++i)
    ss.push_back(new string(words[i]));
  for(size_t i = 0; i < ss.size(); ++i)
    cout << *ss[i] << ' ';
  cout << endl;
  ss.sort();
  for(size_t i = 0; i < ss.size(); ++i) {
    cout << *ss[i] << ' ';
    delete ss[i];
  }
  cout << endl;

  // Uses the full char* specialization:
  Sortable<char*> scp;
  for(size_t i = 0; i < asz(words2); ++i)
    scp.push_back(words2[i]);
  for(size_t i = 0; i < scp.size(); ++i)
    cout << scp[i] << ' ';
  cout << endl;
  scp.sort();
  for(size_t i = 0; i < scp.size(); ++i)
    cout << scp[i] << ' ';
  cout << endl;
} ///:~
