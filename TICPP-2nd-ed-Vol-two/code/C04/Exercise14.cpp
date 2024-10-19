//: C04:Exercise14.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <fstream>
#include <iostream>
#include <sstream>
#include "../require.h"
using namespace std;

#define d(a) cout << #a " ==\t" << a << endl;

void tellPointers(fstream& s) {
  d(s.tellp());
  d(s.tellg());
  cout << endl;
}
void tellPointers(stringstream& s) {
  d(s.tellp());
  d(s.tellg());
  cout << endl;
}
int main() {
  fstream in("Exercise14.cpp");
  assure(in, "Exercise14.cpp");
  in.seekg(10);
  tellPointers(in);
  in.seekp(20);
  tellPointers(in);
  stringstream memStream("Here is a sentence.");
  memStream.seekg(10);
  tellPointers(memStream);
  memStream.seekp(5);
  tellPointers(memStream);
} ///:~
