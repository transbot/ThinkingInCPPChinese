//: C11:Interrupting.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Interrupting a blocked thread.
//{L} ZThread
#include <iostream>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

class Blocked : public Runnable {
public:
  void run() {
    try {
      Thread::sleep(1000);
      cout << "Waiting for get() in run():";
      cin.get();
    } catch(Interrupted_Exception&) {
      cout << "Caught Interrupted_Exception" << endl;
      // Exit the task
    }
  }
};

int main(int argc, char* argv[]) {
  try {
    Thread t(new Blocked);
    if(argc > 1)
      Thread::sleep(1100);
    t.interrupt();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
