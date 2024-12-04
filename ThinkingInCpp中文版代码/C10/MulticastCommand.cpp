//: C10:MulticastCommand.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ������ģʽ�����¼�����
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// ����ִ�п��
class Task {
public:
    virtual void operation() = 0; // ���麯��
};

class TaskRunner {
    static vector<Task*> tasks;
    TaskRunner() {} // ����ģʽ
    TaskRunner& operator=(TaskRunner&); // ������ֵ
    TaskRunner(const TaskRunner&); // ������������
    static TaskRunner tr;

public:
    static void add(Task& t) {
        tasks.push_back(&t);
    }
    static void run() {
        vector<Task*>::iterator it = tasks.begin();
        while(it != tasks.end()) {
            (*it++)->operation();
        }
    }
};

TaskRunner TaskRunner::tr;
vector<Task*> TaskRunner::tasks;

class EventSimulator {
    clock_t creation;
    clock_t delay;

public:
    EventSimulator() : creation(clock()) {
        delay = CLOCKS_PER_SEC / 4 * (rand() % 20 + 1);
        cout << "�ӳ� = " << delay << endl;
    }
    bool fired() {
        return clock() > creation + delay;
    }
};

// ���ࣨButton���Ķ�����������첽�¼�
class Button {
    bool pressed;
    string id;
    EventSimulator e; // ������ʾ

public:
    Button(string name) : pressed(false), id(name) {}
    void press() {
        pressed = true;
    }
    bool isPressed() {
        if(e.fired()) {
            press(); // ģ�ⰴť�����¼�
        }
        return pressed;
    }
    friend ostream& operator<<(ostream& os, const Button& b) {
        return os << b.id;
    }
};

// �������
class CheckButton : public Task {
    Button& button;
    bool handled;

public:
    CheckButton(Button& b) : button(b), handled(false) {}
    void operation() {
        if(button.isPressed() && !handled) {
            cout << button << "������" << endl;
            handled = true;
        }
    }
};

// ���¹���ִ�г������Ҫ������������Ҫ���ڡ��жϡ��Լ�鰴ť�������¼���״̬
void procedure1() {
    // ������ִ��procedure1�Ĳ�����
    // ...
    TaskRunner::run(); // ��������¼�
}

void procedure2() {
    // ������ִ��procedure2�Ĳ�����
    // ...
    TaskRunner::run(); // ��������¼�
}

void procedure3() {
    // ������ִ��procedure3�Ĳ�����
    // ...
    TaskRunner::run(); // ��������¼�
}

int main() {
    srand(time(0)); // �����
    Button b1("��ť1"), b2("��ť2"), b3("��ť3");
    CheckButton cb1(b1), cb2(b2), cb3(b3);
    TaskRunner::add(cb1);
    TaskRunner::add(cb2);
    TaskRunner::add(cb3);
    cout << "��Ctrl+C�˳�" << endl;
    while(true) {
        procedure1();
        procedure2();
        procedure3();
    }
} ///:~
