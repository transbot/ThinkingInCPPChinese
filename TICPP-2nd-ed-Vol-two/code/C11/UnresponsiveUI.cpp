//: C11:UnresponsiveUI.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Lack of threading produces an unresponsive UI.
//{L} ZThread
#include <iostream>
#include <fstream>
#include <string>
#include "zthread/Thread.h"
using namespace std;
using namespace ZThread;

int main() {
  cout << "Press <Enter> to quit:" << endl;
  ifstream file("UnresponsiveUI.cpp");
  string line;
  while(getline(file, line)) {
    cout << line << endl;
    Thread::sleep(1000); // Time in milliseconds
  }
  // Read input from the console
  cin.get();
  cout << "Shutting down..." << endl;
} ///:~
