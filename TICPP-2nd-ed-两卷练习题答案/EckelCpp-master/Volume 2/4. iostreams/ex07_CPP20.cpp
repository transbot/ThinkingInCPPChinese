/*
 �ַ�����֧�ּ򵥵�ת����������һ���Ĵ��ۡ���дһ������
 �Ա�atoi()��stringstreamת��ϵͳ��
 ���stringstream�������Ŀ�����
*/

#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <string>
#include <chrono>

// ʹ�� atoi ����ת��
void atoiConversion(const std::vector<std::string>& strings) {
    for (const auto& str : strings) {
        int num = atoi(str.c_str());
        // �����κδ���ֻ��Ϊ��ģ��ת��
    }
}

// ʹ�� std::stringstream ����ת��
void stringstreamConversion(const std::vector<std::string>& strings) {
    for (const auto& str : strings) {
        int num;
        std::stringstream ss(str);
        ss >> num;
        // �����κδ���ֻ��Ϊ��ģ��ת��
    }
}

int main() {
    // ��������ַ�������
    std::vector<std::string> testStrings;
    for (int i = 0; i < 1000000; ++i) {
        testStrings.push_back(std::to_string(i));
    }

    // ����atoiת����ʱ��
    auto startAtoi = std::chrono::high_resolution_clock::now();
    atoiConversion(testStrings);
    auto endAtoi = std::chrono::high_resolution_clock::now();
    auto durationAtoi = std::chrono::duration_cast<std::chrono::milliseconds>(endAtoi - startAtoi);

    // ����std::stringstreamת����ʱ��
    auto startStrstream = std::chrono::high_resolution_clock::now();
    stringstreamConversion(testStrings);
    auto endStrstream = std::chrono::high_resolution_clock::now();
    auto durationStrstream = std::chrono::duration_cast<std::chrono::milliseconds>(endStrstream - startStrstream);

    // ������
    std::cout << "atoiת������ " << durationAtoi.count() << " ���롣" << std::endl;
    std::cout << "std::stringstreamת������ " << durationStrstream.count() << " ���롣" << std::endl;

    return 0;
}