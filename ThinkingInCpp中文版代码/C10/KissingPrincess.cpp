//: C10:KissingPrincess.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���´���δʹ�á�״̬��ģʽ
#include <iostream>
using namespace std;

class Creature {
    bool isFrog; // ��������
public:
    Creature() : isFrog(true) {}
    void greet() {
        if (isFrog) // ��������ܣ����á����ɡ������к�
            cout << "����!" << endl;
        else // ����������ӣ���ô�á��װ��ġ������к�
            cout << "�װ���!" << endl;
    }
    void kiss() { 
        isFrog = false; // ���Ǻ����ܱ������
    }
};

int main() {
    Creature creature; // ����һ��������󣬳�ʼ״̬������
    creature.greet();  // ���ܴ��к�
    creature.kiss();   // �������ܣ����ܱ������
    creature.greet();  // ���Ӵ��к�
} ///:~
