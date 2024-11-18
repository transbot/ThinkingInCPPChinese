//: C07:PriorityQueue3.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示更复杂的优先队列
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class ToDoItem {
    char primary;  // 主要优先级
    int secondary; // 次要优先级
    string item;   // 待办事项本身

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
    toDoList.push(ToDoItem("Empty trash(倒垃圾)", 'C', 4));
    toDoList.push(ToDoItem("Feed dog(喂狗)", 'A', 2));
    toDoList.push(ToDoItem("Feed bird(喂鸟)", 'B', 7));
    toDoList.push(ToDoItem("Mow lawn(割草)", 'C', 3));
    toDoList.push(ToDoItem("Water lawn(浇水)", 'A', 1));
    toDoList.push(ToDoItem("Feed cat(喂猫)", 'B', 1));

    while(!toDoList.empty()) {
        cout << toDoList.top() << endl;
        toDoList.pop();
    }
} ///:~
