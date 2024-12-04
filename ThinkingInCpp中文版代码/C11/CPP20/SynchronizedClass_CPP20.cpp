//: C11:SynchronizedClass_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include <iostream>
#include <mutex>
#include <memory>

// 定义一个模板类，用于自动同步类的所有成员函数
template <typename T>
class GuardedClass {
private:
    std::unique_ptr<T> obj;
    std::mutex mutex;
        
public:
    explicit GuardedClass(T* ptr) : obj(std::move(ptr)), mutex() {}

    // 重载->操作符，支持const和非const调用
    T* operator->() {
        std::lock_guard<std::mutex> lock(mutex);
        return obj.get();
    }

    const T* operator->() const {
        std::lock_guard<std::mutex> lock(mutex);
        return obj.get();
    }
};

// 示例类MyClass
class MyClass {
public:
    void func1() {
        std::cout << "调用了func1" << std::endl;
    }

    void func2() {
        std::cout << "调用了func2" << std::endl;
    }
};

int main() {
    MyClass a;
    a.func1(); // 未同步
    a.func2(); // 未同步

    GuardedClass<MyClass> b(new MyClass);
    // 同步所有调用，每次只允许一个线程：
    b->func1();
    b->func2();

    return 0;
}