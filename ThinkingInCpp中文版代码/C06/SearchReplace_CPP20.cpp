//: C06:SearchReplace_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// STL���Һ��滻�㷨
#include <algorithm>
#include <functional>
#include <vector>
#include "PrintSequence.h" // ��������һ���Զ����ͷ�ļ������ڴ�ӡ����
using namespace std;

// �Զ���ν�ʣ�������������Ƿ�����j == i + 1
struct PlusOne { 
    bool operator()(int i, int j) { return j == i + 1; } 
};

// �Զ���ν�ʣ�������������ĳ˻��Ƿ���ڸ���ֵ
class MulMoreThan { 
    int value;
public: 
    MulMoreThan(int val) : value(val) {} 
    bool operator()(int v, int m) { 
        return v * m > value; 
    } 
};

int main() { 
    // ��ʼ��һ����������
    int a[] = { 1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 8, 8, 8, 8, 11, 11, 11, 11, 11 }; 
    const int ASZ = sizeof a / sizeof *a; // ��������Ĵ�С
    vector<int> v(a, a + ASZ);            // ������ת��Ϊvector
    print(v.begin(), v.end(), "v", " ");  // ��ӡ����v������
    
    // ʹ��find����ֵ4
    vector<int>::iterator it = find(v.begin(), v.end(), 4); 
    cout << "find: " << *it << endl; 
    
    // ʹ��find_if���Ҵ���8��ֵ
    // �ִ�C++Ӧʹ��lambda���ʽ�滻bind2nd��
    // it = find_if(v.begin(), v.end(), bind2nd(greater<int>(), 8)); 
    it = find_if(v.begin(), v.end(), [](int x) { return x > 8; });
    // ���ߣ�
    // it = find_if(v.begin(), v.end(), [&](int x) { return greater<int>()(x, 8); });
    cout << "find_if: " << *it << endl; 
    
    // ʹ��adjacent_find�������ڵ��ظ�Ԫ��
    it = adjacent_find(v.begin(), v.end()); 
    while(it != v.end()) { 
        cout << "adjacent_find: " << *it << ", " << *(it + 1) << endl; 
        it = adjacent_find(it + 1, v.end()); 
    } 
    
    // ʹ��adjacent_find���Զ���ν��PlusOne��������Ԫ������j == i + 1�����
    it = adjacent_find(v.begin(), v.end(), PlusOne()); 
    while(it != v.end()) { 
        cout << "adjacent_find PlusOne: " << *it << ", " << *(it + 1) << endl; 
        it = adjacent_find(it + 1, v.end(), PlusOne()); 
    } 
    
    // ��ʼ����һ����������b
    int b[] = { 8, 11 }; 
    const int BSZ = sizeof b / sizeof *b; // ��������b�Ĵ�С
    print(b, b + BSZ, "b", " ");          // ��ӡ����b������
    
    // ʹ��find_first_of��������v�е�һ��Ҳ������b�е�Ԫ��
    it = find_first_of(v.begin(), v.end(), b, b + BSZ); 
    print(it, it + BSZ, "find_first_of", " "); 
    
    // ʹ��find_first_of���Զ���ν��PlusOne��������v�е�һ������������Ԫ�أ�
    // ��Ԫ��������b�е�Ԫ������j == i + 1��
    it = find_first_of(v.begin(), v.end(), b, b + BSZ, PlusOne()); 
    print(it, it + BSZ, "find_first_of PlusOne", " "); 
    
    // ʹ��search��������b������v�е�������
    it = search(v.begin(), v.end(), b, b + BSZ); 
    print(it, it + BSZ, "search", " "); 
    
    // ��ʼ����һ����������c
    int c[] = { 5, 6, 7 }; 
    const int CSZ = sizeof c / sizeof *c; // ��������c�Ĵ�С
    print(c, c + CSZ, "c", " ");          // ��ӡ����c������

    // ʹ��search���Զ���ν��PlusOne��������c������v�е������У�
    // Ҫ������j == i + 1��
    it = search(v.begin(), v.end(), c, c + CSZ, PlusOne()); 
    print(it, it + CSZ, "search PlusOne", " "); 
    
    // ��ʼ����һ����������d
    int d[] = { 11, 11, 11 }; 
    const int DSZ = sizeof d / sizeof *d; // ��������d�Ĵ�С
    print(d, d + DSZ, "d", " ");          // ��ӡ����d������
    
    // ʹ��find_end��������d������v�е����һ�γ���
    it = find_end(v.begin(), v.end(), d, d + DSZ); 
    print(it, v.end(), "find_end", " ");  // ��it��ʼ��ӡv��ʣ�ಿ��
    
    // ��ʼ����һ����������e
    int e[] = { 9, 9 }; 
    print(e, e + 2, "e", " "); // ��ӡ����e������
    
    // ʹ��find_end���Զ���ν��PlusOne��������d������v�е����һ�γ��֣�
    // Ҫ������j == i + 1��
    it = find_end(v.begin(), v.end(), e, e + 2, PlusOne()); 
    print(it, v.end(), "find_end PlusOne", " "); 
    
    // ʹ��search_n����������v����������3�ε�ֵ7
    it = search_n(v.begin(), v.end(), 3, 7); 
    print(it, it + 3, "search_n 3, 7", " "); 
    
    // ʹ��search_n���Զ���ν��MulMoreThan������v�в�������6��ֵ��
    // �����Ǹ��Գ���15ʱ�����������100��    
    it = search_n(v.begin(), v.end(), 6, 15, MulMoreThan(100)); 
    print(it, it + 6, "search_n 6, 15, MulMoreThan(100)", " "); 
    
    // ʹ��min_element��������v�е���Сֵ
    cout << "min_element: " << *min_element(v.begin(), v.end()) << endl; 
    
    // ʹ��max_element��������v�е����ֵ
    cout << "max_element: " << *max_element(v.begin(), v.end()) << endl; 
    
    // ʹ��replace_copy������v�е�����8�滻Ϊ47����������Ŀ����洢������v2��
    vector<int> v2; 
    replace_copy(v.begin(), v.end(), back_inserter(v2), 8, 47); 
    print(v2.begin(), v2.end(), "replace_copy 8 -> 47", " "); 
    
    // ʹ��replace_if������v�����д��ڵ���7��ֵ�滻Ϊ-1
    // �ִ�C++Ӧʹ��lambda���ʽ�滻bind2nd��
    // replace_if(v.begin(), v.end(), bind2nd(greater_equal<int>(), 7), -1); 
    replace_if(v.begin(), v.end(), [&](int x) { return greater_equal<int>()(x, 7); }, -1);
    // ���ߣ�
    // replace_if(v.begin(), v.end(), [&](int x) { return greater_equal<int>()(x, 7); }, -1);
    print(v.begin(), v.end(), "replace_if >= 7 -> -1", " "); 
} ///:~