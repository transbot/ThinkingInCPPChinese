//: C06:CountNotEqual_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <algorithm> 
#include <cstddef> 
#include <iostream> 
using namespace std;

// ͳ�Ʋ�����20��Ԫ�ص�����(ʹ��lambda���ʽ)
int main() {
    int a[] = { 10, 20, 30 };
    const size_t SIZE = sizeof a / sizeof a[0]; 

    // ʹ��lambda���ʽ
    int count = count_if(a, a + SIZE, [](int x) { return x != 20; }); 
    cout << count << endl; // ��� 2
}