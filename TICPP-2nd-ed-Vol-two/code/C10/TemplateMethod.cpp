//: C10:TemplateMethod.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Simple demonstration of Template Method.
#include <iostream>
using namespace std;

class ApplicationFramework {
protected:
  virtual void customize1() = 0;
  virtual void customize2() = 0;
public:
  void templateMethod() {
    for(int i = 0; i < 5; i++) {
      customize1();
      customize2();
    }
  }
};

// Create a new "application":
class MyApp : public ApplicationFramework {
protected:
  void customize1() { cout << "Hello "; }
  void customize2() { cout << "World!" << endl; }
};

int main() {
  MyApp app;
  app.templateMethod();
} ///:~
