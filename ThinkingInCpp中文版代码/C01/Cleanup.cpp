//: C01:Cleanup.cpp
// 抛出异常后，只有已构造完毕的对象才会被清理
#include <iostream>
using namespace std;

class Trace {    
    static int counter;  // 全局int计数器
    int objid;
public:
    Trace() {
        objid = counter++;
        cout << "正在构造Trace对象#" << objid << endl;
        if (objid == 3) throw 3;
    }

    ~Trace() {
        cout << "正在析构Trace对象#" << objid << endl;
    }
};

int Trace::counter = 0;

int main() {
    try {
        Trace n1;

        // 创建Trace对象数组的过程中抛出了异常：
        Trace array[5];

        Trace n2; // 永远执行不到这里
    } catch (int i) {
        cout << "捕获" << i << endl;
    }
} ///:~
