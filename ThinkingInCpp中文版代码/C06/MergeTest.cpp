//: C06:MergeTest.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// ���Զ�������Χִ�С��ϲ���
//{L} Generators
#include <algorithm>
#include "PrintSequence.h"
#include "Generators.h"
using namespace std;

int main() {
    const int SZ = 15;
    int a[SZ*2] = {0};

    // ���ɵ�����������Χ���ŵ�ͬһ��������
    generate(a, a + SZ, SkipGen(0, 2));
    a[3] = 4; a[4] = 4;
    generate(a + SZ, a + SZ*2, SkipGen(1, 3));

    // ��ӡa��������
    print(a, a + SZ, "��Χ1", " ");
    print(a + SZ, a + SZ*2, "��Χ2", " ");

    int b[SZ*2] = {0}; // ������Ԫ�ض���ʼ��Ϊ��
    
    merge(a, a + SZ, a + SZ, a + SZ*2, b); // ��a�������ֺϲ���b��
    print(b, b + SZ*2, "ִ��merge", " ");  // ��ӡ�ϲ���Ľ�� 
    
    // ����b
    for(int i = 0; i < SZ*2; i++)
        b[i] = 0;

    // ԭ�غϲ�
    inplace_merge(a, a + SZ, a + SZ*2);
    print(a, a + SZ*2, "ִ��inplace_merge", " ");
    int* end = set_union(a, a + SZ, a + SZ, a + SZ*2, b);
    print(b, end, "set_union", " ");
} ///:~
