/*
Modify Reversible.cpp so it works with deque and list instead of vector.
*/

//: C07:Reversible.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
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
