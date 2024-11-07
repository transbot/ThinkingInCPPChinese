//: C06:InsertVector.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��һ������������׷�ӵ���һ��������
#include <algorithm> 
#include <cassert> 
#include <cstddef> 
#include <iterator> 
#include <vector>
using namespace std;

int main() { 
    int a[] = { 10, 20, 30 }; 
    const size_t SIZE = sizeof a / sizeof a[0]; 
    vector<int> v1(a, a + SIZE); 
    vector<int> v2; // v2�˴�Ϊ��
    copy(v1.begin(), v1.end(), back_inserter(v2)); 
    assert(equal(v1.begin(), v1.end(), v2.begin()));
} ///:~
