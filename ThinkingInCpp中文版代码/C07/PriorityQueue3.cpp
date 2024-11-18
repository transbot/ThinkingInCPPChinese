//: C07:PriorityQueue3.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ�����ӵ����ȶ���
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class ToDoItem {
    char primary;  // ��Ҫ���ȼ�
    int secondary; // ��Ҫ���ȼ�
    string item;   // ���������

public:
    ToDoItem(string td, char pri = 'A', int sec = 1) : 
        primary(pri), secondary(sec), item(td) {}

    friend bool operator<(const ToDoItem& x, const ToDoItem& y) {
        if(x.primary > y.primary) return true;
        if(x.primary == y.primary && x.secondary > y.secondary) return true;
        return false;
    }

    friend ostream& operator<<(ostream& os, const ToDoItem& td) {
        return os << td.primary << td.secondary << ": " << td.item;
    }
};

int main() {
    priority_queue<ToDoItem> toDoList;
    toDoList.push(ToDoItem("Empty trash(������)", 'C', 4));
    toDoList.push(ToDoItem("Feed dog(ι��)", 'A', 2));
    toDoList.push(ToDoItem("Feed bird(ι��)", 'B', 7));
    toDoList.push(ToDoItem("Mow lawn(���)", 'C', 3));
    toDoList.push(ToDoItem("Water lawn(��ˮ)", 'A', 1));
    toDoList.push(ToDoItem("Feed cat(ιè)", 'B', 1));

    while(!toDoList.empty()) {
        cout << toDoList.top() << endl;
        toDoList.pop();
    }
} ///:~
