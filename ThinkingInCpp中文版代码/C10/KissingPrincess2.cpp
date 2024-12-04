//: C10:KissingPrincess2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��״̬ģʽ
#include <iostream>
#include <string>
using namespace std;

class Creature {
    // ����һ��״̬�ӿ�
    class State {
    public:
        virtual string response() = 0; // ���麯����������Ӧ��Ϊ
    };

    // ��������״̬��
    class Frog : public State {
    public:
        string response() { return "����!"; } // ���ܵ���Ӧ
    };

    // ��������״̬��
    class Prince : public State {
    public:
        string response() { return "�װ���!"; } // ���ӵ���Ӧ
    };

    State* state; // ��ǰ״ָ̬��

public:
    // ���캯������ʼ״̬Ϊ����
    Creature() : state(new Frog()) {}

    // ���к������ݵ�ǰ״̬���ز�ͬ����Ӧ
    void greet() { cout << state->response() << endl; }

    // ���ǣ���״̬�����ܱ�Ϊ����
    void kiss() {
        delete state; // ���ٵ�ǰ״̬����
        state = new Prince(); // �����µ�����״̬����
    }

    // �����������ͷ�״̬����
    ~Creature() {
        delete state;
    }
};

int main() {
    Creature creature; // ����һ��������󣬳�ʼ״̬������
    creature.greet();  // ���ܴ��к�
    creature.kiss();   // �������ܣ����ܱ������
    creature.greet();  // ���Ӵ��к�
} ///:~