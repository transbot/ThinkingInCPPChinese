//: C10:MulticastCommand.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用命令模式解耦事件管理
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// 任务执行框架
class Task {
public:
    virtual void operation() = 0; // 纯虚函数
};

class TaskRunner {
    static vector<Task*> tasks;
    TaskRunner() {} // 单例模式
    TaskRunner& operator=(TaskRunner&); // 不允许赋值
    TaskRunner(const TaskRunner&); // 不允许拷贝构造
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
        cout << "延迟 = " << delay << endl;
    }
    bool fired() {
        return clock() > creation + delay;
    }
};

// 该类（Button）的对象可能生成异步事件
class Button {
    bool pressed;
    string id;
    EventSimulator e; // 用于演示

public:
    Button(string name) : pressed(false), id(name) {}
    void press() {
        pressed = true;
    }
    bool isPressed() {
        if(e.fired()) {
            press(); // 模拟按钮按下事件
        }
        return pressed;
    }
    friend ostream& operator<<(ostream& os, const Button& b) {
        return os << b.id;
    }
};

// 命令对象
class CheckButton : public Task {
    Button& button;
    bool handled;

public:
    CheckButton(Button& b) : button(b), handled(false) {}
    void operation() {
        if(button.isPressed() && !handled) {
            cout << button << "被按下" << endl;
            handled = true;
        }
    }
};

// 以下过程执行程序的主要操作，它们需要定期“中断”以检查按钮或其他事件的状态
void procedure1() {
    // 在这里执行procedure1的操作。
    // ...
    TaskRunner::run(); // 检查所有事件
}

void procedure2() {
    // 在这里执行procedure2的操作。
    // ...
    TaskRunner::run(); // 检查所有事件
}

void procedure3() {
    // 在这里执行procedure3的操作。
    // ...
    TaskRunner::run(); // 检查所有事件
}

int main() {
    srand(time(0)); // 随机化
    Button b1("按钮1"), b2("按钮2"), b3("按钮3");
    CheckButton cb1(b1), cb2(b2), cb3(b3);
    TaskRunner::add(cb1);
    TaskRunner::add(cb2);
    TaskRunner::add(cb3);
    cout << "按Ctrl+C退出" << endl;
    while(true) {
        procedure1();
        procedure2();
        procedure3();
    }
} ///:~
