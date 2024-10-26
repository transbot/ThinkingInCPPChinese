//: C05:DotTemplate_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ�����C++20��Concepts�����޸�ԭʾ������
// �������cl /EHsc DotTemplate_CPP20.cpp /std:c++20
#include <bitset>
#include <cstddef>
#include <iostream>
#include <string>
#include <concepts>
#include <charconv>

// ����һ�����ȷ��charT��һ���ַ�����
template<typename T>
concept CharType = std::is_same_v<T, char> || std::is_same_v<T, wchar_t>;

template<CharType charT, size_t N>
std::basic_string<charT> bitsetToString(const std::bitset<N>& bs) {
    return bs.to_string();
}

int main() {
    std::bitset<10> bs;
    bs.set(1);
    bs.set(5);
    std::cout << bs << std::endl; // �����0000100010
    std::string s = bitsetToString<char>(bs);
    std::cout << s << std::endl;  // �����0000100010
}