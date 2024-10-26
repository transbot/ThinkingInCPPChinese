//: C05:Accumulate.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����ʱ��һ������������Ϊ��������
#include <iostream>
using namespace std;

// �ۼ�F(0)��F(n)�Ľ��
template<int n, template<int> class F> struct Accumulate {
    enum { val = Accumulate<n-1, F>::val + F<n>::val };
};

// ֹͣ����������F(0)��ֵ��
template<template<int> class F> struct Accumulate<0, F> {
    enum { val = F<0>::val };
};

// ���֡���������
template<int n> struct Identity {
    enum { val = n };
};

template<int n> struct Square { // ƽ��
    enum { val = n*n };
};

template<int n> struct Cube {   // ����
    enum { val = n*n*n };
};

int main() {
    cout << Accumulate<4, Identity>::val << endl; // 1-4�ۼӣ�10
    cout << Accumulate<4, Square>::val << endl;   // 1-4�ֱ���ƽ������ӣ�30
    cout << Accumulate<4, Cube>::val << endl;     // 1-4�ֱ�����������ӣ�100
} ///:~
