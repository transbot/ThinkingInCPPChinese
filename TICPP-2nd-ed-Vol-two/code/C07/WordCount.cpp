//: C07:WordCount.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Count occurrences of words using a map.
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
  typedef map<string, int> WordMap;
  typedef WordMap::iterator WMIter;
  const char* fname = "WordCount.cpp";
  if(argc > 1) fname = argv[1];
  ifstream in(fname);
  assure(in, fname);
  WordMap wordmap;
  string word;
  while(in >> word)
    wordmap[word]++;
  for(WMIter w = wordmap.begin(); w != wordmap.end(); w++)
    cout << w->first << ": " << w->second << endl;
} ///:~
