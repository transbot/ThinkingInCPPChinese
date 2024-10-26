//: C05:StrTolower_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ�����ַ���ת��ΪСд�ķ�����������ȡ��ע����ʵ��
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <ranges>

int main() {
    std::string s("LOWER");

    // ʹ��lambda���ʽ����ȷ����tolower����
    // �����lambda���ʽ��[](char c) { return std::tolower(c); }
    std::transform(s.begin(), s.end(), s.begin(), [](char c) {
        return std::tolower(c);
    });
    std::cout << s << std::endl;

    // ʹ��C++20�����std::ranges���ԣ�����������cl /EHsc StrTolower_CPP20.cpp /std:c++20
    // std::ranges::transform(s, s.begin(), [](char c) { return std::tolower(c); });
    // std::cout << s << std::endl;

    // ʹ���Զ��庯������
    // struct ToLower {
    //     char operator()(char c) const {
    //         return std::tolower(c);
    //     }
    // };    
    // std::transform(s.begin(), s.end(), s.begin(), ToLower());
    // std::cout << s << std::endl;

    return 0;
}