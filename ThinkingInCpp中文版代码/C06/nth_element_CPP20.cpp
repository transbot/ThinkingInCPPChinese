//: C06:nth_element_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾnth_element�㷨��Ч��
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // ��ʼ����
    std::vector<int> v = {7, 2, 8, 4, 6, 3, 1};

    // ����Ŀ��λ��
    auto nth = v.begin() + 2;  // ��3��Ԫ��

    // ��ӡ����ǰ�Ľ��
    std::cout << "����ǰ������: ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // ʹ��Ĭ�ϱȽ�ν�ʽ��в�������
    // ֻ��֤��1��Ԫ�ص���3��Ԫ��(nth)�����򣬵�4��Ԫ�ص���5��Ԫ�ز���֤
    // ���һ��Ԫ�أ���1������[first, last]�ķ�Χ��
    std::nth_element(v.begin(), nth, v.begin()+4); // v.begin()+4��λ����5��Ԫ��

    // ��ӡ���������Ľ��
    std::cout << "����������: ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // �����3��Ԫ��
    std::cout << "�����ĵ�3��Ԫ��: " << *nth << std::endl;

    // ��������
    // ����ǰ������: 7 2 8 4 6 3 1
    // ����������: 2 4 7 8 6 3 1
    // �����ĵ�3��Ԫ��: 7

    return 0;
}