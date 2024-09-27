//: C07:WordList2.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Illustrates istreambuf_iterator and insert iterators.
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
  char* fname = "WordList2.cpp";
  if(argc > 1) fname = argv[1];
  ifstream in(fname);
  assure(in, fname);
  istreambuf_iterator<char> p(in), end;
  set<string> wordlist;
  while(p != end) {
    string word;
    insert_iterator<string> ii(word, word.begin());
    // Find the first alpha character:
    while(p != end && !isalpha(*p))
      ++p;
    // Copy until the first non-alpha character:
    while(p != end && isalpha(*p))
      *ii++ = *p++;
    if(word.size() != 0)
      wordlist.insert(word);
  }
  // Output results:
  copy(wordlist.begin(), wordlist.end(),
    ostream_iterator<string>(cout, "\n"));
} ///:~
