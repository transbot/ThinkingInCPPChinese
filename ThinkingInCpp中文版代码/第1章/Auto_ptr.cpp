//: C01:Auto_ptr.cpp
// 演示auto_ptr的RAII特性
#include <memory>
#include <iostream>
#include <cstddef>
using namespace std;

class TraceHeap {
    int i;
public:
    static void* operator new(size_t siz) {
        void* p = ::operator new(siz);
        cout << "在堆的地址" << p << "处分配了一个TraceHeap对象" << endl;
        return p;
    }

    static void operator delete(void* p) {
        cout << "释放了地址" << p << "处的TraceHeap对象" << endl;
        ::operator delete(p);
    }

    TraceHeap(int i) : i(i) {}
    int getVal() const { return i; }
};

int main() {
    auto_ptr<TraceHeap> pMyObject(new TraceHeap(5));
    cout << pMyObject->getVal() << endl; // 输出5
} ///:~
