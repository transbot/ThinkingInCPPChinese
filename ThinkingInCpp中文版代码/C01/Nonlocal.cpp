//: C01:Nonlocal.cpp
// 演示setjmp() & longjmp()
#include <iostream>
#include <csetjmp>
using namespace std;

// 代表奥兹魔法世界
class Rainbow {
public:
    Rainbow() { cout << "Rainbow()" << endl; }
    ~Rainbow() { cout << "~Rainbow()" << endl; }
};

jmp_buf kansas; // 保存跳转回的点

// 模拟桃乐丝在奥兹国的经历
void oz() {
    Rainbow rb; // 创建魔法世界
    for (int i = 0; i < 3; i++)
        cout << "没有哪个地方比家更好" << endl;
    // 跳回故事的开头
    longjmp(kansas, 47);
}

int main() {
    // 保存当前执行上下文
    if (setjmp(kansas) == 0) {
        cout << "龙卷风、女巫、芒奇金人..." << endl;
        oz(); // 进入魔法世界
    }
    else {
        // 从梦境中醒来
        cout << "艾姆阿姨! "
            << "我做了个最奇怪的梦..."
            << endl;
    }
} ///:~
