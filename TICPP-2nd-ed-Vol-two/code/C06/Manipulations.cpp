//: C06:Manipulations.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Shows basic manipulations.
//{L} Generators
// NString
#include <vector>
#include <string>
#include <algorithm>
#include "PrintSequence.h"
#include "NString.h"
#include "Generators.h"
using namespace std;

int main() {
  vector<int> v1(10);
  // Simple counting:
  generate(v1.begin(), v1.end(), SkipGen());
  print(v1.begin(), v1.end(), "v1", " ");
  vector<int> v2(v1.size());
  copy_backward(v1.begin(), v1.end(), v2.end());
  print(v2.begin(), v2.end(), "copy_backward", " ");
  reverse_copy(v1.begin(), v1.end(), v2.begin());
  print(v2.begin(), v2.end(), "reverse_copy", " ");
  reverse(v1.begin(), v1.end());
  print(v1.begin(), v1.end(), "reverse", " ");
  int half = v1.size() / 2;
  // Ranges must be exactly the same size:
  swap_ranges(v1.begin(), v1.begin() + half,
    v1.begin() + half);
  print(v1.begin(), v1.end(), "swap_ranges", " ");
  // Start with a fresh sequence:
  generate(v1.begin(), v1.end(), SkipGen());
  print(v1.begin(), v1.end(), "v1", " ");
  int third = v1.size() / 3;
  for(int i = 0; i < 10; i++) {
    rotate(v1.begin(), v1.begin() + third, v1.end());
    print(v1.begin(), v1.end(), "rotate", " ");
  }
  cout << "Second rotate example:" << endl;
  char c[] = "aabbccddeeffgghhiijj";
  const char CSZ = strlen(c);
  for(int i = 0; i < 10; i++) {
    rotate(c, c + 2, c + CSZ);
    print(c, c + CSZ, "", "");
  }
  cout << "All n! permutations of abcd:" << endl;
  int nf = 4 * 3 * 2 * 1;
  char p[] = "abcd";
  for(int i = 0; i < nf; i++) {
    next_permutation(p, p + 4);
    print(p, p + 4, "", "");
  }
  cout << "Using prev_permutation:" << endl;
  for(int i = 0; i < nf; i++) {
    prev_permutation(p, p + 4);
    print(p, p + 4, "", "");
  }
  cout << "random_shuffling a word:" << endl;
  string s("hello");
  cout << s << endl;
  for(int i = 0; i < 5; i++) {
    random_shuffle(s.begin(), s.end());
    cout << s << endl;
  }
  NString sa[] = { "a", "b", "c", "d", "a", "b",
    "c", "d", "a", "b", "c", "d", "a", "b", "c"};
  const int SASZ = sizeof sa / sizeof *sa;
  vector<NString> ns(sa, sa + SASZ);
  print(ns.begin(), ns.end(), "ns", " ");
  vector<NString>::iterator it =
    partition(ns.begin(), ns.end(),
      bind2nd(greater<NString>(), "b"));
  cout << "Partition point: " << *it << endl;
  print(ns.begin(), ns.end(), "", " ");
  // Reload vector:
  copy(sa, sa + SASZ, ns.begin());
  it = stable_partition(ns.begin(), ns.end(),
    bind2nd(greater<NString>(), "b"));
  cout << "Stable partition" << endl;
  cout << "Partition point: " << *it << endl;
  print(ns.begin(), ns.end(), "", " ");
} ///:~
