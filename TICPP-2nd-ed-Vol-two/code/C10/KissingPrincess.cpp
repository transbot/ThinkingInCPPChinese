//: C10:KissingPrincess.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
using namespace std;

class Creature {
  bool isFrog;
public:
  Creature() : isFrog(true) {}
  void greet() {
    if(isFrog)
      cout << "Ribbet!" << endl;
    else
      cout << "Darling!" << endl;
  }
  void kiss() { isFrog = false; }
};

int main() {
  Creature creature;
  creature.greet();
  creature.kiss();
  creature.greet();
} ///:~
