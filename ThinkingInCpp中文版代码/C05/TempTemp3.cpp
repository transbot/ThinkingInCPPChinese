//: C05:TempTemp3.cpp {-bor}{-msc}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 作为模板传递的模板参数及其默认实参
#include <cstddef>
#include <iostream>
using namespace std;

template<class T, size_t N = 10> // 设置了一个默认实参
class Array {
    T data[N];
    size_t count;
public:
    Array() { count = 0; }
    void push_back(const T& t) {
        if(count < N)
            data[count++] = t;
    }
    void pop_back() {
        if(count > 0)
            --count;
    }
    T* begin() { return data; }
    T* end() { return data + count; }
};

// 必须重复默认实参
template<class T, template<class, size_t = 10> class Seq>
class Container {
    Seq<T> seq; // 这里使用了默认实参
public:
    void append(const T& t) { seq.push_back(t); }
    T* begin() { return seq.begin(); }
    T* end() { return seq.end(); }
};

int main() {
    Container<int, Array> container;
    container.append(1);
    container.append(2);
    int* p = container.begin();
    while(p != container.end())
        cout << *p++ << endl;
} ///:~
