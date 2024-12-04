//: C11:ResponsiveUI.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ͨ�����̴߳�����ʵ����Ӧ������UI
#include <iostream>
#include <fstream>
#include <string>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

class DisplayTask : public Runnable {
    ifstream in;
    string line;
    bool quitFlag;

public:
    DisplayTask(const string& file) : quitFlag(false) {
        in.open(file.c_str());
    }
    ~DisplayTask() {
        in.close();
    }
    void run() {
        while(getline(in, line) && !quitFlag) {
            cout << line << endl;
            Thread::sleep(1000);
        }
    }
    void quit() {
        quitFlag = true;
    }
};

int main() {
    try {
        cout << "�밴<Enter>���˳�:" << endl;
        DisplayTask* dt = new DisplayTask("ResponsiveUI.cpp");
        Thread t(dt);
        cin.get();
        dt->quit();
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
    cout << "���ڹر�..." << endl;
} ///:~
