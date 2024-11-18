//: C07:MatrixMultiply.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用valarray实现矩阵乘法
#include <cassert>
#include <cstddef>
#include <cmath>
#include <iostream>
#include <iomanip> // 为了使用setw
#include <valarray>
using namespace std;

// 将valarray作为方阵（square matrix）打印，即行列数相等的矩阵
template<class T>
void printMatrix(const valarray<T>& a, size_t n) {
    size_t siz = n * n;                     // 计算矩阵的总元素数
    assert(siz <= a.size());                // 确保矩阵的总元素数不超过valarray的大小
    for (size_t i = 0; i < siz; ++i) {      // 遍历所有元素
        cout << setw(5) << a[i];            // 输出当前元素，域宽设为5
        cout << ((i + 1) % n ? ' ' : '\n'); // 如果不是每行的最后一个元素，那么输出空格；否则换行
    }
    cout << endl;
}

// 对两个valarray中的兼容矩阵执行乘法运算
template<class T>
valarray<T> matmult(const valarray<T>& a, size_t arows, size_t acols,
                    const valarray<T>& b, size_t brows, size_t bcols) {
    assert(acols == brows);                  // 确保第一个矩阵的列数等于第二个矩阵的行数
    valarray<T> result(arows * bcols);       // 创建结果矩阵，大小为arows * bcols

    for (size_t i = 0; i < arows; ++i)       // 遍历结果矩阵的每一行
        for (size_t j = 0; j < bcols; ++j) { // 遍历结果矩阵的每一列
            // 计算行a[i]和列b[j]的点积
            valarray<T> row = a[slice(acols * i, acols, 1)]; // 获取矩阵a的第i行
            valarray<T> col = b[slice(j, brows, bcols)];     // 获取矩阵b的第j列
            result[i * bcols + j] = (row * col).sum();       // 计算点积并存储到结果矩阵中
        }
    return result; // 返回结果矩阵
}

int main() {
    const int n = 3;                     // 定义矩阵的维度
    int adata[n * n] = {1, 0, -1, 2, 2, -3, 3, 4, 0};  // 在矩阵a中填充数据
    int bdata[n * n] = {3, 4, -1, 1, -3, 0, -1, 1, 2}; // 在矩阵b中填充数据
    valarray<int> a(adata, n * n);       // 创建valarray a
    valarray<int> b(bdata, n * n);       // 创建valarray b

    valarray<int> c(matmult(a, n, n, b, n, n)); // 计算矩阵乘法结果
    printMatrix(c, n);                          // 打印结果矩阵c
} ///:~