//: C07:WordList.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Display a list of words used in a document.
#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include "../require.h"
using namespace std;

char replaceJunk(char c) {
  // Only keep alphas, space (as a delimiter), and '
  return (isalpha(c) || c == '\'') ? c : ' ';
}

int main(int argc, char* argv[]) {
  char* fname = "WordList.cpp";
  if(argc > 1) fname = argv[1];
  ifstream in(fname);
  assure(in, fname);
  set<string> wordlist;
  string line;
  while(getline(in, line)) {
    transform(line.begin(), line.end(), line.begin(),
              replaceJunk);
    istringstream is(line);
    string word;
    while(is >> word)
      wordlist.insert(word);
  }
  // Output results:
  copy(wordlist.begin(), wordlist.end(),
       ostream_iterator<string>(cout, "\n"));
} ///:~
