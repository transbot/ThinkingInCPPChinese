//: C02:MemTest.cpp
//{L} MemCheck
// ����MemCheck����
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include "MemCheck.h" // ������������
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
    // ��������ȡ����һ��ע��֮��Ľ��
    // TRACE_OFF();
    MEM_ON();
    cout << "���" << endl;
    int* p = new int;
    delete p;
    int* q = new int[3];
    delete [] q;
    int* r = nullptr;  // ���ⴴ��һ����ָ��  
    delete r;    
    vector<int> v;
    v.push_back(1);
    Foo s("�ټ�");
    MEM_OFF();
} ///:~
