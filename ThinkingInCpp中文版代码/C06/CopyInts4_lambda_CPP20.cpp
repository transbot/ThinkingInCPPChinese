//: C06:CopyInts4_lambda_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    int a[] = { 10, 20, 30 };
    const size_t SIZE = sizeof a / sizeof a[0];

    // ʹ��lambda���ʽ
    // ����Ŀǰ����δ���ܳ�һ��ʱ�������
    remove_copy_if(a, a + SIZE,
                  ostream_iterator<int>(cout, "\n"),
                  [](int x) { return x > 15; });

    // ע�ͣ�
    // - [](int x) { return x > 15; }��һ��lambda���ʽ����������һ��������������
    // - x��ʾ��ǰ��������Ԫ�ء�
    // - ����x > 15�Ľ�������жϵ�ǰԪ���Ƿ����15��
    // - ��ˣ����յ�Ч���ǽ�����a�в�����15��Ԫ�ظ��Ƶ��������
    // - ����д�����Ӽ��ֱ�ۡ�
}
