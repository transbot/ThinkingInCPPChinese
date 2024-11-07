//: C06:adjacent_find_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ���ҡ�����Ԫ�ء����㷨
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 2, 4, 5, 5};
    // ���ԭʼvector������ 
    std::cout << "ԭʼvector ��";
    for (int num : numbers) { std::cout << num << " "; }
    std::cout << std::endl;

    // �������ڵ��������Ԫ�أ�ʹ��Ĭ�ϵ�==��������
    auto it = std::adjacent_find(numbers.begin(), numbers.end());
    if (it != numbers.end()) {
        std::cout << "�ҵ������ڵ��������Ԫ�أ�" << *it << std::endl;
    }

    // �������ڵ�����Ԫ�أ����е�һ��Ԫ��С�ڵڶ���Ԫ��
    auto it2 = std::adjacent_find(numbers.begin(), numbers.end(), [](int x, int y) { return x < y; });
    if (it2 != numbers.end()) {
        std::cout << "�ҵ������ڵ�����Ԫ�أ���һ��С�ڵڶ�����" << *it2 << " " << *(it2 + 1) << std::endl;
    }

    return 0;
}