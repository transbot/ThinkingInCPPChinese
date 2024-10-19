//: C01:Autoexcp.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// No matching conversions.
#include <iostream>
using namespace std;

class Except1 {};

class Except2 {
public:
  Except2(const Except1&) {}
};

void f() { throw Except1(); }

int main() {
  try { f();
  } catch(Except2&) {
    cout << "inside catch(Except2)" << endl;
  } catch(Except1&) {
    cout << "inside catch(Except1)" << endl;
  }
} ///:~
