//: C08:CatchBadCast.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <typeinfo>
#include "Security.h"
using namespace std;

int main() {
  Metal m;
  Security& s = m;
  try {
    Investment& c = dynamic_cast<Investment&>(s);
    cout << "It's an Investment" << endl;
  } catch(bad_cast&) {
    cout << "s is not an Investment type" << endl;
  }
  try {
    Bond& b = dynamic_cast<Bond&>(s);
    cout << "It's a Bond" << endl;
  } catch(bad_cast&) {
    cout << "It's not a Bond type" << endl;
  }
} ///:~
