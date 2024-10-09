//: C01:Auto_ptr_CPP20.cpp
// 演示智能指针unique_ptr的RAII特性
// 
// 代码分析与改进：
// 使用unique_ptr：unique_ptr表示对一个对象的独占所有权，当unique_ptr销毁时，它指向的对象也会被删除。这符合我们对auto_ptr的原始意图。
// 使用make_unique：std::make_unique是C++14引入的工厂函数，用于创建unique_ptr对象，可以避免手动调用new和delete，减少出错的可能性。
// 删除不必要的头文件：cstddef头文件在现代C++中已经很少使用，直接使用std::size_t即可。


#include <memory>
#include <iostream>
using namespace std;

class TraceHeap {
public:
    static void* operator new(std::size_t size) {
        void* ptr = ::operator new(size);
        cout << "在堆的地址" << ptr << "处分配了一个TraceHeap对象" << endl;
        return ptr;
    }

    static void operator delete(void* ptr) {
        cout << "释放了地址" << ptr << "处的TraceHeap对象" << endl;
        ::operator delete(ptr);
    }

    TraceHeap(int i) : i(i) {}
    int getVal() const { return i; }

private:
    int i;
};

int main() {
    // 使用unique_ptr来管理TraceHeap对象
    unique_ptr<TraceHeap> pMyObject = make_unique<TraceHeap>(5);
    cout << pMyObject->getVal() << endl; // 输出5
} ///:~