//: C05:Unroll.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ͨ������չ��һ����ʽ��ѭ��
#include <iostream>
using namespace std;

// ��n����1ʱ���ݹ������������m��n-1���ݣ�Ȼ�����m
template<int n> inline int power(int m) {
    return power<n-1>(m) * m;
}

// ģ���ػ����κ�����1���ݶ���������
template<> inline int power<1>(int m) {
    return m;
}

// ģ���ػ����κ�����0���ݶ�Ϊ1
template<> inline int power<0>(int m) {
    return 1;
}

int main() {
    int m = 4;
    cout << power<3>(m) << endl; // 64
} ///:~
