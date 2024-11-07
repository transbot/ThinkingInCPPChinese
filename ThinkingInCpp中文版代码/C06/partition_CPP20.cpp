//: C06:partition_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾpartition��stable_partition�Ĺ��ܺ�����
// ��1-10������ִ����ż������
#include <iostream>
#include <vector>
#include <algorithm>

// ����һ���ж��Ƿ�ż����ν�ʺ���
bool is_even(int x) {
    return x % 2 == 0;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // ���ԭʼvector������ 
    std::cout << "ԭʼvector ��";
    for (int num : v) { std::cout << num << " "; }
    std::cout << std::endl;

    // ʹ��partition()
    std::vector<int> v1 = v;
    auto it1 = std::partition(v1.begin(), v1.end(), is_even);
    std::cout << "ִ��partition()��";
    for (auto it = v1.begin(); it != it1; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "| ";
    for (auto it = it1; it != v1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // ʹ��stable_partition()
    std::vector<int> v2 = v;
    auto it2 = std::stable_partition(v2.begin(), v2.end(), is_even);
    std::cout << "ִ��stable_partition()��";
    for (auto it = v2.begin(); it != it2; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "| ";
    for (auto it = it2; it != v2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}