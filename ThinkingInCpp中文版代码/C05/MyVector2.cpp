//: C05:MyVector2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ�ñ��ʽģ�崦�����ⳤ�ȵ���ͱ��ʽ
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// ���ڱ�ʾ�������͡��Ĵ�����
template<class T, size_t N, class Left, class Right> class MyVectorSum;

template<class T, size_t N> class MyVector {
    T data[N];
public:
    MyVector<T,N>& operator=(const MyVector<T,N>& right) {
        for(size_t i = 0; i < N; ++i)
            data[i] = right.data[i];
        return *this;
    }
    template<class Left, class Right> MyVector<T,N>&
    operator=(const MyVectorSum<T, N, Left, Right>& right);
    const T& operator[](size_t i) const {
        return data[i];
    }
    T& operator[](size_t i) {
        return data[i];
    }
};

// ������ʹ��MyVector��MyVectorSum
template<class T, size_t N, class Left, class Right> class MyVectorSum {
    const Left& left;
    const Right& right;
public:
    MyVectorSum(const Left& lhs, const Right& rhs) : left(lhs), right(rhs) {}
    T operator[](size_t i) const {
        return left[i] + right[i];
    }
};

template<class T, size_t N>
template<class Left, class Right>
MyVector<T,N>& MyVector<T,N>::
    operator=(const MyVectorSum<T, N, Left, Right>& right) {
    for(size_t i = 0; i < N; ++i)
        data[i] = right[i];
    return *this;
}

// operator+ֻ�洢����
template<class T, size_t N>
inline MyVectorSum<T, N, MyVector<T,N>, MyVector<T,N> >
operator+(const MyVector<T,N>& left, const MyVector<T,N>& right) {
    return MyVectorSum<T, N, MyVector<T,N>, MyVector<T,N> >(left, right);
}

template<class T, size_t N, class Left, class Right>
inline MyVectorSum<T, N, MyVectorSum<T, N, Left, Right>, MyVector<T,N> >
operator+(const MyVectorSum<T, N, Left,
          Right>& left, const MyVector<T,N>& right) {
    return MyVectorSum<T, N, MyVectorSum<T, N, Left, Right>,
        MyVector<T,N>>(left, right);
}

// Ϊ�Ժ�Ĳ��Գ����ṩ�����ĸ���������init��print��
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
    // ����֧���ˣ�
    MyVector<int, 5> v4;
    v4 = v1 + v2 + v3;
    print(v4);
    MyVector<int, 5> v5;
    v5 = v1 + v2 + v3 + v4;
    print(v5);
} ///:~
