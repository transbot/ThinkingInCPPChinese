//: C11:BasicThreads.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Thread���������Ӧ��
//{L} ZThread
#include <iostream>
#include "LiftOff.h"
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

int main() {
    try {
        Thread t(new LiftOff(10));
        cout << "��𵹼�ʱ" << endl;
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
