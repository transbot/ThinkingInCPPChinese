//: C07:DequeOverflow.cpp {-bor}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// A deque is much more efficient than a vector when
// pushing back a lot of elements, since it doesn't
// require copying and destroying.
//{L} Noisy
#include <cstdlib>
#include <deque>
#include "Noisy.h"
using namespace std;

int main(int argc, char* argv[]) {
  int size = 1000;
  if(argc >= 2) size = atoi(argv[1]);
  deque<Noisy> dn;
  Noisy n;
  for(int i = 0; i < size; i++)
    dn.push_back(n);
  cout << "\n cleaning up " << endl;
} ///:~
