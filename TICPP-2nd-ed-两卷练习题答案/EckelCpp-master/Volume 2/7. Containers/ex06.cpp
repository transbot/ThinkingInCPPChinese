/*
Modify Reversible.cpp so it works with deque and list instead of vector.
*/

//: C07:Reversible.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Using reversible containers.
#include <fstream>
#include <iostream>
#include <string>
//- #include <vector>
#include <deque> //+
#include <list> //+

using namespace std;

int main() {
  //ifstream in("Reversible.cpp");
  ifstream in("ex06.cpp");
  //assure(in, "Reversible.cpp");
  string line;
  //- vector<string> lines;
  //+ list<string> lines;
  deque<string> lines; //+
  while(getline(in, line))
    lines.push_back(line);
  //- for(vector<string>::reverse_iterator r = lines.rbegin();
  //+ for(list<string>::reverse_iterator r = lines.rbegin();
  for(deque<string>::reverse_iterator r = lines.rbegin(); //+
      r != lines.rend(); r++)
    cout << *r << endl;
} ///:~
