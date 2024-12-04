// C11:UnresponsiveUI_CPP20.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����ȱ�����̴߳�����������һ������Ӧ��UI
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void readAndDisplayFile() {
    ifstream file("UnresponsiveUI_CPP20.cpp");
    string line;
    while(getline(file, line)) {
        cout << line << endl;
        this_thread::sleep_for(chrono::milliseconds(1000)); // ʱ�䵥λΪ����
    }
}

int main() {
    cout << "�밴<Enter>���˳�:" << endl;

    // ����һ���߳�����ȡ����ʾ�ļ�����
    thread fileThread(readAndDisplayFile);

    // �ӿ���̨��ȡ����
    cin.get();

    // �ȴ��ļ���ȡ�߳̽���
    fileThread.join();

    cout << "���ڹر�..." << endl;
    return 0;
}