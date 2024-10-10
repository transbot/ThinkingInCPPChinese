//: C01:FunctionTryBlock.cpp {-bor}
// 函数级的try块
// {RunByHand}（不要通过makefile自动运行）
#include <iostream>
using namespace std;

int main() try {
    throw "main";
} catch (const char* msg) {
    cout << msg << endl;
    return 1;
} ///:~
