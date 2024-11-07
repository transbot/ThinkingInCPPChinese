//: C06:CopyInts4_bind_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

// std::bind��C++11�����һ����ǿ��ĺ����󶨹��ߣ�
// ���԰��κοɵ��ö���Ĳ���������֧�ָ����ӵİ�����
// ����������ô�򵥵�һ�������У����Ե��е㡰���С�á���
// ��ˣ����黻��ʹ��lambda���ʽ���μ���һ�����ӣ���
int main() {
    int a[] = { 10, 20, 30 };
    const size_t SIZE = sizeof a / sizeof a[0];

    // ʹ��std::bind��15��Ϊgreater<int>�ĵڶ���ʵ��
    remove_copy_if(a, a + SIZE,
                  ostream_iterator<int>(cout, "\n"),
                  bind(greater<int>(), placeholders::_1, 15));

    // ע�ͣ�
    // - bind(greater<int>(), placeholders::_1, 15)������һ���µĿɵ��ö���
    // - placeholders::_1��ʾ������remove_copy_if�ĵ�һ��ʵ�ΰ󶨵�greater<int>�ĵ�һ��������
    // - 15ֱ�Ӱ󶨵�greater<int>�ĵڶ���ʵ�Ρ�
    // - ��ˣ����յ�Ч���ǽ�����a�в�����15��Ԫ�ظ��Ƶ��������
}