//: C04:Datascan.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} DataLogger
#include <fstream>
#include <iostream>
#include "DataLogger.h"
#include "../require.h"
using namespace std;

int main() {
  ifstream bindata("data.bin", ios::binary);
  assure(bindata, "data.bin");
  DataPoint d;
  while(bindata.read(reinterpret_cast<char*>(&d),
         sizeof d))
    cout << d << endl;
} ///:~
