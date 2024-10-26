//: C05:MyVector.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 通过模板优化掉临时变量
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// 用于表示“向量和”的代理类
template<class T, size_t N> class MyVectorSum;

template<class T, size_t N> class MyVector {
    T data[N];
public:
    MyVector<T,N>& operator=(const MyVector<T,N>& right) {
        for(size_t i = 0; i < N; ++i)
            data[i] = right.data[i];
        return *this;
    }
    MyVector<T,N>& operator=(const MyVectorSum<T,N>& right);
    const T& operator[](size_t i) const { return data[i]; }
    T& operator[](size_t i) { return data[i]; }
};

// 代理类容纳了引用，并使用延迟加法
template<class T, size_t N> class MyVectorSum {
    const MyVector<T,N>& left;
    const MyVector<T,N>& right;
public:
    MyVectorSum(const MyVector<T,N>& lhs,
                const MyVector<T,N>& rhs)
                    : left(lhs), right(rhs) {}
    T operator[](size_t i) const {
        return left[i] + right[i];
    }
};

// 用于支持v3 = v1 + v2的操作符
template<class T, size_t N> MyVector<T,N>&
MyVector<T,N>::operator=(const MyVectorSum<T,N>& right) {
    for(size_t i = 0; i < N; ++i)
        data[i] = right[i];
    return *this;
}

// operator+只存储引用
template<class T, size_t N> inline MyVectorSum<T,N>
operator+(const MyVector<T,N>& left, const MyVector<T,N>& right) {
    return MyVectorSum<T,N>(left, right);
}

// 为稍后的测试程序提供便利的辅助函数（init和print）
template<class T, size_t N> void init(MyVector<T,N>& v) {
    for(size_t i = 0; i < N; ++i)
        v[i] = rand() % 100;
}

template<class T, size_t N> void print(MyVector<T,N>& v) {
    for(size_t i = 0; i < N; ++i)
        cout << v[i] << ' ';
    cout << endl;
}

int main() {
    srand(time(0));
    MyVector<int, 5> v1;
    init(v1);
    print(v1);
    MyVector<int, 5> v2;
    init(v2);
    print(v2);
    MyVector<int, 5> v3;
    v3 = v1 + v2;
    print(v3);
    MyVector<int, 5> v4;
    // 还不支持：
    // v4 = v1 + v2 + v3;
} ///:~
