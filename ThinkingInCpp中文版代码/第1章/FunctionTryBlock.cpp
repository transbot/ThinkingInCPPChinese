//: C01:FunctionTryBlock.cpp {-bor}
// ��������try��
// {RunByHand}����Ҫͨ��makefile�Զ����У�
#include <iostream>
using namespace std;

int main() try {
    throw "main";
} catch (const char* msg) {
    cout << msg << endl;
    return 1;
} ///:~
