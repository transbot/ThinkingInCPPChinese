//: C11:UnresponsiveUI.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
//{L} ZThread

// ����ȱ�����̴߳�����������һ������Ӧ��UI
#include <iostream>
#include <fstream>
#include <string>
#include "zthread/Thread.h"

using namespace std;
using namespace ZThread;

int main() {
    cout << "�밴<Enter>���˳�:" << endl;
    ifstream file("UnresponsiveUI.cpp");
    string line;
    while(getline(file, line)) {
        cout << line << endl;
        Thread::sleep(1000); // ʱ�䵥λΪ����
    }
    // �ӿ���̨��ȡ����
    cin.get();
    cout << "���ڹر�..." << endl;
} ///:~
