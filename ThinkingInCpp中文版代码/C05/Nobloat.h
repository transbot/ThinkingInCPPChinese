//: C05:Nobloat.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 共享在栈中存储指针的逻辑
#ifndef NOBLOAT_H
#define NOBLOAT_H
#include <cassert>
#include <cstddef>
#include <cstring>

// 主模板
template<class T> class Stack {
    T* data;
    std::size_t count;
    std::size_t capacity;
    enum { INIT = 5 };
public:
    Stack() {
        count = 0;
        capacity = INIT;
        data = new T[INIT];
    }

    void push(const T& t) {
        if (count == capacity) { // 扩展数组
            std::size_t newCapacity = 2 * capacity;
            T* newData = new T[newCapacity];
            for (size_t i = 0; i < count; ++i)
                newData[i] = data[i];
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        assert(count < capacity);
        data[count++] = t;
    }

    void pop() {
        assert(count > 0);
        --count;
    }

    T top() const {
        assert(count > 0);
        return data[count - 1];
    }

    std::size_t size() const { return count; }
};

// 针对void*的全特化
template<> class Stack<void*> {
    void** data;
    std::size_t count;
    std::size_t capacity;
    enum { INIT = 5 };
public:
    Stack() {
        count = 0;
        capacity = INIT;
        data = new void*[INIT];
    }

    void push(void* const& t) {
        if (count == capacity) {
            std::size_t newCapacity = 2 * capacity;
            void** newData = new void*[newCapacity];
            std::memcpy(newData, data, count * sizeof(void*));
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        assert(count < capacity);
        data[count++] = t;
    }

    void pop() {
        assert(count > 0);
        --count;
    }

    void* top() const {
        assert(count > 0);
        return data[count - 1];
    }

    std::size_t size() const {
        return count;
    }
};

// 针对其他指针类型的偏特化
template<class T> class Stack<T*> : private Stack<void*> {
    typedef Stack<void*> Base;
public:
    void push(T* const& t) { Base::push(t); }
    void pop() { Base::pop(); }
    T* top() const { return static_cast<T*>(Base::top()); }
    std::size_t size() { return Base::size(); }
};
#endif // NOBLOAT_H ///:~
