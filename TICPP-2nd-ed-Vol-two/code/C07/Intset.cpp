//: C07:Intset.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Simple use of STL set.
#include <cassert>
#include <set>
using namespace std;

int main() {
  set<int> intset;
  for(int i = 0; i < 25; i++)
    for(int j = 0; j < 10; j++)
      // Try to insert duplicates:
      intset.insert(j);
  assert(intset.size() == 10);
} ///:~
