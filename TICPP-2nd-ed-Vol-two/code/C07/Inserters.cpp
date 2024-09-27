//: C07:Inserters.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Different types of iterator inserters.
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
using namespace std;

int a[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23 };

template<class Cont> void frontInsertion(Cont& ci) {
  copy(a, a + sizeof(a)/sizeof(Cont::value_type),
    front_inserter(ci));
  copy(ci.begin(), ci.end(),
    ostream_iterator<typename Cont::value_type>(
    cout, " "));
  cout << endl;
}

template<class Cont> void backInsertion(Cont& ci) {
  copy(a, a + sizeof(a)/sizeof(Cont::value_type),
    back_inserter(ci));
  copy(ci.begin(), ci.end(),
    ostream_iterator<typename Cont::value_type>(
    cout, " "));
  cout << endl;
}

template<class Cont> void midInsertion(Cont& ci) {
  typename Cont::iterator it = ci.begin();
  ++it; ++it; ++it;
  copy(a, a + sizeof(a)/(sizeof(Cont::value_type) * 2),
    inserter(ci, it));
  copy(ci.begin(), ci.end(),
    ostream_iterator<typename Cont::value_type>(
    cout, " "));
  cout << endl;
}

int main() {
  deque<int> di;
  list<int>  li;
  vector<int> vi;
  // Can't use a front_inserter() with vector
  frontInsertion(di);
  frontInsertion(li);
  di.clear();
  li.clear();
  backInsertion(vi);
  backInsertion(di);
  backInsertion(li);
  midInsertion(vi);
  midInsertion(di);
  midInsertion(li);
} ///:~
