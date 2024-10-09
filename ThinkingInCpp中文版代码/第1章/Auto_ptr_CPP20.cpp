//: C01:Auto_ptr_CPP20.cpp
// ��ʾ����ָ��unique_ptr��RAII����
// 
// ���������Ľ���
// ʹ��unique_ptr��unique_ptr��ʾ��һ������Ķ�ռ����Ȩ����unique_ptr����ʱ����ָ��Ķ���Ҳ�ᱻɾ������������Ƕ�auto_ptr��ԭʼ��ͼ��
// ʹ��make_unique��std::make_unique��C++14����Ĺ������������ڴ���unique_ptr���󣬿��Ա����ֶ�����new��delete�����ٳ���Ŀ����ԡ�
// ɾ������Ҫ��ͷ�ļ���cstddefͷ�ļ����ִ�C++���Ѿ�����ʹ�ã�ֱ��ʹ��std::size_t���ɡ�


#include <memory>
#include <iostream>
using namespace std;

class TraceHeap {
public:
    static void* operator new(std::size_t size) {
        void* ptr = ::operator new(size);
        cout << "�ڶѵĵ�ַ" << ptr << "��������һ��TraceHeap����" << endl;
        return ptr;
    }

    static void operator delete(void* ptr) {
        cout << "�ͷ��˵�ַ" << ptr << "����TraceHeap����" << endl;
        ::operator delete(ptr);
    }

    TraceHeap(int i) : i(i) {}
    int getVal() const { return i; }

private:
    int i;
};

int main() {
    // ʹ��unique_ptr������TraceHeap����
    unique_ptr<TraceHeap> pMyObject = make_unique<TraceHeap>(5);
    cout << pMyObject->getVal() << endl; // ���5
} ///:~