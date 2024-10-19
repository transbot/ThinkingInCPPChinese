//: C10:CollectingParameterDemo.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CollectingParameter : public vector<string> {};

class Filler {
public:
  void f(CollectingParameter& cp) {
    cp.push_back("accumulating");
  }
  void g(CollectingParameter& cp) {
    cp.push_back("items");
  }
  void h(CollectingParameter& cp) {
    cp.push_back("as we go");
  }
};

int main() {
  Filler filler;
  CollectingParameter cp;
  filler.f(cp);
  filler.g(cp);
  filler.h(cp);
  vector<string>::iterator it = cp.begin();
  while(it != cp.end())
    cout << *it++ << " ";
  cout << endl;
} ///:~
