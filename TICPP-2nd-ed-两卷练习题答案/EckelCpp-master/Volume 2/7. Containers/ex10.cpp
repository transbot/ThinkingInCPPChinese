/*
Modify WordCount.cpp so that it uses insert( )
instead of operator[ ] to insert elements in the map.
*/

//: C07:WordCount.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Count occurrences of words using a map.
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  typedef map<string, int> WordMap;
  typedef WordMap::iterator WMIter;
  const char* fname = "ex09.txt";
  //if(argc > 1) fname = argv[1];
  ifstream in(fname);
  //assure(in, fname);
  WordMap wordmap;
  string word;

  while(in >> word) {

	  auto it = wordmap.find(word);

	  if ( it == wordmap.end() )
		  wordmap.insert(std::make_pair(word, 1));
	  else
		  it->second++;
  }

  for(WMIter w = wordmap.begin(); w != wordmap.end(); w++)
    cout << w->first << ": " << w->second << endl;
} ///:~
