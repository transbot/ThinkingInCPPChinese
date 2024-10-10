//: C01:Nonlocal2.cpp
// 演示异常处理。
#include <iostream>
using namespace std;

// 代表奥兹魔法世界
class Rainbow {
public:
    Rainbow() { cout << "Rainbow()" << endl; }
    ~Rainbow() { cout << "~Rainbow()" << endl; }
};

// 模拟桃乐丝在奥兹国的经历
void oz() {
    Rainbow rb;
    for(int i = 0; i < 3; i++)
        cout << "没有哪个地方比家更好" << endl;
    throw 47;
}

int main() {
    try {
        cout << "龙卷风、女巫、芒奇金人..." << endl;
        oz(); // 进入魔法世界
    } catch(int) {
        cout << "艾姆阿姨! "
             << "我做了个最奇怪的梦..."
             << endl;
    }
} ///:~
