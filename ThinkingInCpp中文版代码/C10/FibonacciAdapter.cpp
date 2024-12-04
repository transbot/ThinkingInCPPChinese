//: C10:FibonacciAdapter.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �����еĽӿ���һ��Ŀ��ӿ�����
#include <iostream>
#include <numeric>
#include "FibonacciGenerator.h"
#include "../C06/PrintSequence.h"
using namespace std;

class FibonacciAdapter {
    // ���ɵ�����
    FibonacciGenerator f; // �ڲ�ʹ�õ�쳲�������������
    int length; // ���еĳ���

public:
    // ���캯������ʼ�����г���
    FibonacciAdapter(int size) : length(size) {}

    // �����ڲ���������
    class iterator;
    friend class iterator; // ����������FibonacciAdapter����Ԫ��

    // �������࣬�̳��Ա�׼���������
    class iterator : public std::iterator<std::input_iterator_tag, FibonacciAdapter, ptrdiff_t> {
        FibonacciAdapter& ap; // �����ⲿ��FibonacciAdapter����

    public:
        typedef int value_type; // ��������ֵ����Ϊint

        // ���캯������ʼ��������
        iterator(FibonacciAdapter& a) : ap(a) {}

        // �Ƚ������������Ƿ����
        bool operator==(const iterator& other) const {
            return ap.f.count() == ap.length;
        }

        // �Ƚ������������Ƿ����
        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }

        // �����õ����������ص�ǰ쳲�������
        int operator*() const {
            return ap.f();
        }

        // ǰ׺����������
        iterator& operator++() {
            return *this;
        }

        // ��׺����������
        iterator operator++(int) {
            iterator temp = *this;
            return temp;
        }
    };

    // �������е���ʼ������
    iterator begin() {
        return iterator(*this);
    }

    // �������еĽ���������
    iterator end() {
        return iterator(*this);
    }
};

int main() {
    const int SZ = 20; // ���г���

    // ����һ������Ϊ20��쳲���������������
    FibonacciAdapter a1(SZ);

    // ����쳲��������е��ۼӺ�
    cout << "accumulate(�ۼӺ�): " << accumulate(a1.begin(), a1.end(), 0) << endl;

    // ������������Ϊ20��쳲���������������
    FibonacciAdapter a2(SZ), a3(SZ);

    // ��������쳲��������е��ڻ�
    cout << "inner product(�ڻ�): " 
         << inner_product(a2.begin(), a2.end(), a3.begin(), 0) << endl;

    // ����һ������Ϊ20��쳲���������������
    FibonacciAdapter a4(SZ);

    // ����쳲��������еĲ��ֺ�
    int r1[SZ] = {0};
    int* end1 = partial_sum(a4.begin(), a4.end(), r1);
    print(r1, end1, "partial_sum(���ֺ�)", " ");

    // ����һ������Ϊ20��쳲���������������
    FibonacciAdapter a5(SZ);

    // ����쳲��������е����ڲ�ֵ
    int r2[SZ] = {0};
    int* end2 = adjacent_difference(a5.begin(), a5.end(), r2);
    print(r2, end2, "adjacent_difference(���ڲ�)", " ");
} ///:~