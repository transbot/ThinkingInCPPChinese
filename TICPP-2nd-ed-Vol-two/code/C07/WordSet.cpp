//: C07:WordSet.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include "../require.h"
using namespace std;

void wordSet(const char* fileName) {
  ifstream source(fileName);
  assure(source, fileName);
  string word;
  set<string> words;
  while(source >> word)
    words.insert(word);
  copy(words.begin(), words.end(),
    ostream_iterator<string>(cout, "\n"));
  cout << "Number of unique words:"
       << words.size() << endl;
}

int main(int argc, char* argv[]) {
  if(argc > 1)
    wordSet(argv[1]);
  else
    wordSet("WordSet.cpp");
} ///:~
