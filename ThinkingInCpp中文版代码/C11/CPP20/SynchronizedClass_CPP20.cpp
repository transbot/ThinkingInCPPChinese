//: C11:SynchronizedClass_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#include <iostream>
#include <mutex>
#include <memory>

// ����һ��ģ���࣬�����Զ�ͬ��������г�Ա����
template <typename T>
class GuardedClass {
private:
    std::unique_ptr<T> obj;
    std::mutex mutex;
        
public:
    explicit GuardedClass(T* ptr) : obj(std::move(ptr)), mutex() {}

    // ����->��������֧��const�ͷ�const����
    T* operator->() {
        std::lock_guard<std::mutex> lock(mutex);
        return obj.get();
    }

    const T* operator->() const {
        std::lock_guard<std::mutex> lock(mutex);
        return obj.get();
    }
};

// ʾ����MyClass
class MyClass {
public:
    void func1() {
        std::cout << "������func1" << std::endl;
    }

    void func2() {
        std::cout << "������func2" << std::endl;
    }
};

int main() {
    MyClass a;
    a.func1(); // δͬ��
    a.func2(); // δͬ��

    GuardedClass<MyClass> b(new MyClass);
    // ͬ�����е��ã�ÿ��ֻ����һ���̣߳�
    b->func1();
    b->func2();

    return 0;
}