//: C02:MemTest.cpp
//{L} MemCheck
// 测试MemCheck机制
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include "MemCheck.h" // 必须最后包含！
using namespace std;

class Foo {
    char* s;
public:
    Foo(const char* s) {
        this->s = new char[strlen(s) + 1];
        strcpy(this->s, s);
    }
    ~Foo() { delete [] s; }
};

int main() {
    // 可以试验取消下一行注释之后的结果
    // TRACE_OFF();
    MEM_ON();
    cout << "你好" << endl;
    int* p = new int;
    delete p;
    int* q = new int[3];
    delete [] q;
    int* r = nullptr;  // 故意创建一个空指针  
    delete r;    
    vector<int> v;
    v.push_back(1);
    Foo s("再见");
    MEM_OFF();
} ///:~
