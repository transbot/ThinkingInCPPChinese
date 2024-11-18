//: C07:MatrixMultiply.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��valarrayʵ�־���˷�
#include <cassert>
#include <cstddef>
#include <cmath>
#include <iostream>
#include <iomanip> // Ϊ��ʹ��setw
#include <valarray>
using namespace std;

// ��valarray��Ϊ����square matrix����ӡ������������ȵľ���
template<class T>
void printMatrix(const valarray<T>& a, size_t n) {
    size_t siz = n * n;                     // ����������Ԫ����
    assert(siz <= a.size());                // ȷ���������Ԫ����������valarray�Ĵ�С
    for (size_t i = 0; i < siz; ++i) {      // ��������Ԫ��
        cout << setw(5) << a[i];            // �����ǰԪ�أ������Ϊ5
        cout << ((i + 1) % n ? ' ' : '\n'); // �������ÿ�е����һ��Ԫ�أ���ô����ո񣻷�����
    }
    cout << endl;
}

// ������valarray�еļ��ݾ���ִ�г˷�����
template<class T>
valarray<T> matmult(const valarray<T>& a, size_t arows, size_t acols,
                    const valarray<T>& b, size_t brows, size_t bcols) {
    assert(acols == brows);                  // ȷ����һ��������������ڵڶ������������
    valarray<T> result(arows * bcols);       // ����������󣬴�СΪarows * bcols

    for (size_t i = 0; i < arows; ++i)       // ������������ÿһ��
        for (size_t j = 0; j < bcols; ++j) { // ������������ÿһ��
            // ������a[i]����b[j]�ĵ��
            valarray<T> row = a[slice(acols * i, acols, 1)]; // ��ȡ����a�ĵ�i��
            valarray<T> col = b[slice(j, brows, bcols)];     // ��ȡ����b�ĵ�j��
            result[i * bcols + j] = (row * col).sum();       // ���������洢�����������
        }
    return result; // ���ؽ������
}

int main() {
    const int n = 3;                     // ��������ά��
    int adata[n * n] = {1, 0, -1, 2, 2, -3, 3, 4, 0};  // �ھ���a���������
    int bdata[n * n] = {3, 4, -1, 1, -3, 0, -1, 1, 2}; // �ھ���b���������
    valarray<int> a(adata, n * n);       // ����valarray a
    valarray<int> b(bdata, n * n);       // ����valarray b

    valarray<int> c(matmult(a, n, n, b, n, n)); // �������˷����
    printMatrix(c, n);                          // ��ӡ�������c
} ///:~