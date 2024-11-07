//: C06:CopyInts.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʹ����ʽѭ��������intֵ
#include <algorithm>
#include <cassert> 
#include <cstddef> // Ϊ��ʹ��size_t
using namespace std;

int main() {
    int a[] = { 10, 20, 30 };
    const size_t SIZE = sizeof a / sizeof a[0];
    int b[SIZE];
    copy(a, a + SIZE, b);
    for(size_t i = 0; i < SIZE; ++i)
        assert(a[i] == b[i]);
} ///:~
