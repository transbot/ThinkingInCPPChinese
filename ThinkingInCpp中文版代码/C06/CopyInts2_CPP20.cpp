//: C06:CopyInts2_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����������Ե�����
#include <algorithm> 
#include <cstddef> 
#include <iostream> 
using namespace std;

// // һ���Զ���Ķ��ԣ������޸ĳ�lambda���ʽ��
// bool gt15(int x) { 
//     return 15 < x; 
// }

int main() { 
    int a[] = { 10, 20, 30 }; 
    const size_t SIZE = sizeof a / sizeof a[0]; 
    int b[SIZE]; 

    // ʹ��lambda���ʽ��Ϊν��
    int* endb = remove_copy_if(a, a + SIZE, b, [](int x) { return x > 15; });     
    int* beginb = b; 
    while(beginb != endb)
        cout << *beginb++ << endl; // ֻ��ӡ10 
} ///:~
