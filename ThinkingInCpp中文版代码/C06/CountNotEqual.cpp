//: C06:CountNotEqual.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ͳ�Ʋ�����20��Ԫ�ص�����
#include <algorithm> 
#include <cstddef> 
#include <functional> 
#include <iostream> 
using namespace std;

int main() { 
    int a[] = { 10, 20, 30 }; 
    const size_t SIZE = sizeof a / sizeof a[0]; 
    cout << count_if(a, a + SIZE, 
                     not1(bind1st(equal_to<int>(), 20))); // ��� 2 
} ///:~
