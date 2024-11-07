//: C06:FunctionObjects.cpp {-bor}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ��׼C++���е�Ԥ���庯������ģ��
// �����������ִ�C++�����ã�not1��not2��bind2nd��bind1stҲ�����⣩
// �μ������е�ע�ͣ��˽���������/std:c++20���ص�ǰ���±���ͨ��
// {L} Generators
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

template<typename Contain, typename UnaryFunc>
void testUnary(Contain& source, Contain& dest, UnaryFunc f) {
    // ʹ��transform()��4�����汾
    transform(source.begin(), source.end(), dest.begin(), f); 
}

template<typename Contain1, typename Contain2, typename BinaryFunc>
void testBinary(Contain1& src1, Contain1& src2,
    Contain2& dest, BinaryFunc f) {
    // ʹ��transform()��5�����汾      
    transform(src1.begin(), src1.end(), src2.begin(), dest.begin(), f);
}

// ִ�У���ֵ�����ʽ��Ȼ�󽫱��ʽ�����ַ�����������ӡ����У�
#define T(EXPR) EXPR; print(r.begin(), r.end(), "ִ�� " #EXPR " ֮��");

// ���ڲ������ԣ�
#define B(EXPR) EXPR; print(br.begin(), br.end(), "ִ�� " #EXPR " ֮��");

// ���������������
struct BRand {
    bool operator()() {
        return rand() % 2 == 0;
    }
};

int main() {  
    const int SZ = 10;
    const int MAX = 50;
    vector<int> x(SZ), y(SZ), r(SZ);

    // �����������������
    URandGen urg(MAX);
    srand(time(0)); // �����
    generate_n(x.begin(), SZ, urg);
    generate_n(y.begin(), SZ, urg);

    // ÿ��Ԫ�ؼ�1�Է�ֹ�����㣺
    transform(y.begin(), y.end(), y.begin(), bind2nd(plus<int>(), 1));    
    // �������д������ִ�C++��Ӧ��Ϊʹ��lambda���ʽ����Ϊbind2nd�ѱ����ã�
    // transform(y.begin(), y.end(), y.begin(), [](int x) { return x + 1; });

    // ��֤������һ��Ԫ������ȵģ��Բ���equal_to����
    x[0] = y[0];

    print(x.begin(), x.end(), "x");
    print(y.begin(), y.end(), "y");

    // ��ÿһ��x��yԪ��ִ����ѧ���㣬�����������r�У�
    T(testBinary(x, y, r, plus<int>()))       // ��
    T(testBinary(x, y, r, minus<int>()))      // ��
    T(testBinary(x, y, r, multiplies<int>())) // ��
    T(testBinary(x, y, r, divides<int>()))    // ��
    T(testBinary(x, y, r, modulus<int>()))    // ģ��
    T(testUnary(x, r, negate<int>()))         // ȡ��

    vector<bool> br(SZ); // �������ɲ������
    B(testBinary(x, y, br, equal_to<int>())) 
    B(testBinary(x, y, br, not_equal_to<int>())) 
    B(testBinary(x, y, br, greater<int>())) 
    B(testBinary(x, y, br, less<int>())) 
    B(testBinary(x, y, br, greater_equal<int>())) 
    B(testBinary(x, y, br, less_equal<int>()))    
    
    B(testBinary(x, y, br, not2(greater_equal<int>())))
    B(testBinary(x, y, br, not2(less_equal<int>())))
    // ���������д������ִ�C++��Ӧ��Ϊʹ��lambda���ʽ����Ϊnot2�ѱ����ã�
    // B(testBinary(x, y, br, [](int a, int b) { return a < b; }));
    // B(testBinary(x, y, br, [](int a, int b) { return a > b; }));
    // ����ֱ�ӽ�not2�滻Ϊnot_fn��
    // B(testBinary(x, y, br, not_fn(greater_equal<int>())))
    // B(testBinary(x, y, br, not_fn(less_equal<int>())))

    vector<bool> b1(SZ), b2(SZ);
    generate_n(b1.begin(), SZ, BRand());
    generate_n(b2.begin(), SZ, BRand());

    print(b1.begin(), b1.end(), "b1");
    print(b2.begin(), b2.end(), "b2");

    B(testBinary(b1, b2, br, logical_and<int>()))
    B(testBinary(b1, b2, br, logical_or<int>()))
    B(testUnary(b1, br, logical_not<int>()))

    B(testUnary(b1, br, not1(logical_not<int>())))
    // �������д������ִ�C++��Ӧ��Ϊʹ��lambda���ʽ����Ϊnot1�ѱ����ã�
    // B(testUnary(b1, br, [](bool x) { return x; }));
    // ����ֱ�ӽ�not1�滻Ϊnot_fn��
    // B(testUnary(b1, br, not_fn(logical_not<int>())))
} ///:~
